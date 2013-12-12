#line 5 "BigFatInteger2.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long LL;
#define VI   vector<int>
#define VS  vector<string>

#define REP(i,a,b) for(i=a;i<b;i++)
#define REV(i,a,b) for(i=b;i>=a;i--)
#define ALL(v)  v.begin(),v.end()
#define pb push_back
#define MP make_pair

using namespace std;
class BigFatInteger2 {
  public:
  bool p[32005];
  VI pr;

  void primes(){
    memset(p,1,sizeof(p));
    for(int i=2;i<32005;i++)
      if(p[i]){
        pr.pb(i);
        for(int j=i*i;j<32005;j+=i)
          p[j]=0;
      }
  }

  LL power(int& x, int p){
    int cnt = 0;
    while(0==x%p)
      x/=p,cnt++;
    return (LL)cnt;
  }

  string isDivisible(int A, int B, int C, int D) {
    LL a,c;
    if(1==C)  return "divisible";
    if(A==C)  return (B>=D) ? "divisible" : "not divisible";
    primes();

    cout << " length of primes array is " << pr.size() << endl;
    for(int i=0;i<pr.size();i++){
      cout << " " << pr[i] ;
    }
    cout << endl;

    int lim = pr.size();
    for(int i=0;i<lim;i++){
      cout<< "A = " << A << " C = " << C << " pr = "<<pr[i] << endl;
      a = power(A,pr[i])*B;
      c = power(C,pr[i])*D;
      cout<< "a = " <<a << " c = " << c << " pr = "<<pr[i] << endl;
      if(a<c) return "not divisible";
    }
    return "divisible";
  }
};

int main(){
  BigFatInteger2 b1;
  int tcase;
  int a,b,c,d;

  cin >> tcase;
  for (int i = 0; i < tcase; ++i)
  {
    cin>>a>>b>>c>>d;
    cout << b1.isDivisible(a,b,c,d) << endl;
  }
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
