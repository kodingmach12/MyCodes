// END CUT HERE
#line 73 "KingXNewCurrency.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class KingXNewCurrency {
	public:
	int howMany(int a, int b, int x) {
    if(a%x ==0 && b%x==0)
        return -1;
    if(x>a || x>b)
        return 1;
    int ares=0,bres=0,adiff,bdiff;
    if(a%x==0)
        ares+=0;
    else
    {
    adiff=a-x;
    bdiff=b-x;



    }
}
	int howMany(int A, int B, int X) {
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,
113,127,131,137,139,149,151,157,163,167,173,179,181,191,197,199};
int a[46]={0},b[46]={0},x[46]={0};
int total=46,i,j,k,res=0;

for(i=0;i<46;i++)
{
    if(A%primes[i]==0  && A && A!=1)
    {
        a[i]=A/primes[i];
        A/=primes[i];
    }
    if(B%primes[i]==0   && B && B!=1)
    {
        b[i]=B/primes[i];
        B/=primes[i];
    }
    if(X%primes[i]==0  && X && X!=1)
    {
        x[i]=X/primes[i];
        X/=primes[i];
    }
}

if(res)
	}
};
