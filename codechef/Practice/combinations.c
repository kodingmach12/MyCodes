#include<stdio.h>
#include<assert.h>

#define s(n) scanf("%d",&n)
#define sl(n) scanf("%ld",&n)
#define sll(n) scanf("%lld",&n)
#define lli  long long int 
lli bincoeff(lli n,lli k)
{
assert(n>0 && k>=0 && k<=n);
if(k==0 || k==n)
	return 1LL;
if(k==1 || k==n-1 )
	return n;
	lli *c= (lli*) malloc((k+1) * sizeof(lli));
	memset(c,0,sizeof(c));
	lli i,j;
	c[0]=1;
	for(i=1;i<=n;i++)
	{
		j=(i<k)?i:k;
	for(;j>0;j--)
		c[j]=c[j]+c[j-1];

	}

return c[k];
}

int main()
{
long long int  n,k;
sll(n);
sll(k);
	printf("C(%lld %lld)  is %lld",n,k,bincoeff(n,k));

return 0;
}
