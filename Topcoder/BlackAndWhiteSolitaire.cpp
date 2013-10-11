// BEGIN CUT HERE

// END CUT HERE
#line 5 "BlackAndWhiteSolitaire.cpp"

#include<iostream>
#include<string>
#include<vector>

#define fill(a,v)		memset( a, v, sizeof(a) )
#define sz 		size()

#define FOR(i,a,b)  	for( int i=a; i<b; i++)
#define REP(i,n)    	 FOR(i,0,n)
#define pb 		push_back
#define mp		make_pair
#define s(n)		scanf("%d",&n)
#define sl(n)		scanf("%lld",&n)
#define bitcount 	__builtin_popcount
#define gcd 		__gcd
#define maX(a,b)	(a>b?a:b)
#define miN(a,b)	(a<b?a:b)


using namespace std;
class BlackAndWhiteSolitaire {
	public:
	int minimumTurns(string c) {
		int n = c.size(),res1 = 0,res2 =0;

    for(int i=0;i<n;i++){
      if(i%2){
        if(c[i]!='B') res1++;
        else res2++;
      }
      else{
        if(c[i]!='W') res1++;
        else res2++;
      }
    }
    return miN(res1,res2);
	}
};
