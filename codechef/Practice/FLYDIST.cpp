#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
using namespace std;
 
#define MAXN 10
#define MAXM (MAXN*(MAXN-1)/2)
 
int gcd(int a, int b) {
  while (b!=0) {
    int c=a%b;
    a=b;
    b=c;
  }
  return a;
}
 
const int gcd_N = 256;
int gcd_table[gcd_N][gcd_N];
 
void init() {
  for (int a=0;a<gcd_N;a++) {
    for (int b=1;b<gcd_N;b++) {
      gcd_table[a][b]=gcd(a,b);
    }
  }
}
 
class Fraction {
public:
  int n, d;
 
  Fraction() { n=0; d=1; }
  Fraction(int num, int den) {
    int anum=abs(num), aden=abs(den), g;
    if (anum<gcd_N && aden<gcd_N) g=gcd_table[anum][aden];
    else g=gcd(anum,aden);
    if (g!=1) { n=num/g; d=den/g; }
    else { n=num; d=den; }
    if (d<0) { n=-n; d=-d; }
  }
  Fraction(int x) { n=x; d=1; }
 
  Fraction neg() { return Fraction(-n, d); }
  Fraction inv() { return Fraction(d, n); }
  Fraction add(Fraction f) { return Fraction(n*f.d+f.n*d, d*f.d); }
  Fraction sub(Fraction f) { return Fraction(n*f.d-f.n*d, d*f.d); }
  Fraction mul(Fraction f) { return Fraction(n*f.n, d*f.d); }
  Fraction div(Fraction f) { return Fraction(n*f.d, d*f.n); }
 
  int compareTo(Fraction f) { return n*f.d-d*f.n; }
 
  string str() {
    char tmp[20];
    sprintf(tmp,"%d/%d",n,d);
    return tmp;
  }
};
 
const int SN=1000, SM=256;
 
class Simplex { // A*x <= b, max(c*x)
public:
  Fraction t[SN][SM];
  int labelC[SM], labelR[SN];
  int rows[SN], cols[SM], nr, nc;
  int n, m;
 
  Simplex(Fraction A[SN][SM], Fraction b[SN], Fraction c[SM], int N, int M) {
    n=N; m=M;
    for (int j=0;j<m;j++) labelC[j]=j;
    for (int i=0;i<n;i++) labelR[i]=-1;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) t[i][j] = A[i][j];
    for (int i=0;i<n;i++) t[i][m] = b[i];
    for (int j=0;j<m;j++) t[n][j] = c[j];
    t[n][m] = 0;
  }
 
  Fraction solve() {
    Fraction zero = Fraction(0);
    while (true) {
      // pivot column
      int c=-1;
      Fraction best_col = zero;
      for (int i=0;i<m;i++) {
        if (t[n][i].compareTo(best_col)>0) {
          c=i;
          best_col = t[n][i];
        }
      }
      if (c==-1) break;
      // pivot row
      int r=-1;
      Fraction best_ratio = Fraction(-1);
      for (int i=0;i<n;i++) {
        if (t[i][c].compareTo(zero)==0) continue;
        Fraction ratio = t[i][m].div(t[i][c]);
        if (ratio.compareTo(zero)<0) continue;
        if (ratio.compareTo(zero)==0 && t[i][c].compareTo(zero)<0) continue;
        if (best_ratio.compareTo(zero)<0 || ratio.compareTo(best_ratio)<0) {
          r=i; best_ratio=ratio;
        }
      }
      Fraction pivot = t[r][c];
      Fraction inv_pivot = pivot.inv();
      Fraction neg_inv_pivot = inv_pivot.neg();
      // update pivot
      t[r][c] = inv_pivot;
      // update row
      for (int j=0;j<=m;j++) if (j!=c) {
        t[r][j] = t[r][j].mul(inv_pivot);
      }
      // list of other rows and columns to update
      nr=0; nc=0;
      for (int i=0;i<=n;i++) if (i!=r) {
        if (t[i][c].compareTo(zero)!=0) rows[nr++]=i;
      }
      for (int j=0;j<=m;j++) if (j!=c) {
        if (t[r][j].compareTo(zero)!=0) cols[nc++]=j;
      }
      // update other
      for (int i=0;i<nr;i++) {
        int y=rows[i];
        for (int j=0;j<nc;j++) {
      int x=cols[j];
          t[y][x] = t[y][x].sub(t[r][x].mul(t[y][c]));
        }
      }
      // update column
      for (int i=0;i<=n;i++) if (i!=r) {
        t[i][c] = t[i][c].mul(neg_inv_pivot);
      }
      // update labels
      int tmp = labelC[c];
      labelC[c] = labelR[r];
      labelR[r] = tmp;
    }
    return t[n][m].neg();
  }
};
 
Fraction A[SN][SM], b[SN], c[SM];
int n, m;
int e[MAXM][3];
vector<int> next[MAXN], nextE[MAXN];
 
int nA;
int cyc[MAXN], cycE[MAXN], used[MAXN];
void cycles(int id, int d=0) {
  cyc[d]=id;
  int ok=1, complete=0;
  if (d>1) {
    for (int i=0;i<(int)nextE[id].size();i++) {
      int ei=nextE[id][i], id2;
      if (e[ei][0]==id) id2=e[ei][1]; else id2=e[ei][0];
      if (id2==cyc[d-1]) continue;
      if (id2==cyc[0]) { cycE[d]=ei; complete=1; continue; }
      if (used[id2]) { ok=0; break; }
    }
  }
  if (!ok) return;
  if (complete) {
    if (id>cyc[1]) {
      for (int i=0;i<=d;i++) {
        for (int j=0;j<=d;j++) {
          int eid=cycE[j];
          if (j==i) { A[nA][2*eid]=1; A[nA][2*eid+1]=1; }
          else { A[nA][2*eid]=-1; A[nA][2*eid+1]=-1; }
        }
        nA++;
      }
    }
  } else {
    used[id]=1;
    for (int i=0;i<(int)nextE[id].size();i++) {
      int ei=nextE[id][i], id2;
      if (e[ei][0]==id) id2=e[ei][1]; else id2=e[ei][0];
      if (id2<cyc[0] || used[id2]) continue;
      cycE[d]=ei;
      cycles(id2,d+1);
    }
    used[id]=0;
  }
}
 
int main() {
  init();
  // read input
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    for (int j=0;j<3;j++) cin >> e[i][j];
    nextE[e[i][0]].push_back(i);
    nextE[e[i][1]].push_back(i);
    next[e[i][0]].push_back(e[i][1]);
    next[e[i][1]].push_back(e[i][0]);
  }
  // set up linear program
  nA=0;
  for (int i=0;i<n;i++) cycles(i);
  for (int i=0;i<m;i++) {
    A[nA][2*i+1]=1; b[nA]=e[i][2];
    nA++;
    c[2*i]=-1; c[2*i+1]=1;
  }
  // solve
  Simplex s = Simplex(A, b, c, nA, 2*m);
  Fraction f = s.solve();
  f = f.neg();
  for (int i=0;i<m;i++) f = f.add(Fraction(e[i][2]));
  cout << f.str() << endl;
  return 0;
}