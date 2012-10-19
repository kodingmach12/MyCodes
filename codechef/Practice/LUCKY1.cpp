#pragma comment (linker, "/STACK:100000000")
#include <iostream>  
#include <sstream>  
#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <memory>  
#include <cctype>  
#include <string>  
#include <vector>  
#include <list>  
#include <queue>  
#include <deque>  
#include <stack>  
#include <map>  
#include <set>  
#include <algorithm>  
using namespace std; 
  
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i)) 
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i)) 
#define CLEAR(a) memset((a),0,sizeof(a)) 
#define INF 1000000000 
#define PB push_back 
#define ALL(c) (c).begin(), (c).end() 
#define pi 2*acos(0.0) 
#define SQR(a) (a)*(a) 
#define MP make_pair 
#define MAX 100001
  
typedef unsigned long long UInt;
typedef long long Int;
 
int t, n;
map <int, int> M;
Int R[MAX];
 
int F(int x, int c)
{
		int r = 0;
		while (x > 0)
		{
				if (x % 10 == c)
						r++;
				x /= 10;
		}
		return r;
}
 
int main()
{
		M[0]++;
		int s4 = 0, s7 = 0;
		Int res = 0;
		FOR (i,1,MAX)
		{
				int c4 = F(i, 4);
				int c7 = F(i, 7);
				s4 += c4;
				s7 += c7;
				res += M[s4-s7];
				R[i] = res;
				M[s4-s7]++;
		}
 
		scanf("%d", &t);
		FOR (tt,0,t)
		{
				scanf("%d", &n);
				printf("%lld\n", R[n]);
		}
		return 0;
}