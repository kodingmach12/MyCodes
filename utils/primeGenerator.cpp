#include<iostream>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;

long long  generatePrimesToN(long long int n){
	long long int i=2,cnt=0,j,k;
	int flg=0;

	while(i<=n)
	{
		flg=0;
		for(j=2; j*j <= i; j++)
		{
			if( i%j ==0 )
			{
				flg=1;
				break;
			}
		}

		if(!flg)
		{
		  cout<<i<<endl;
			cnt++;
		}
		i++;
	}
	return cnt;
}

void generateNPrimes(long long int n)
{
	long long int i=2,cnt=0,j,k;
	int flg=0;

	while(cnt<n)
	{
		flg=0;
		for(j=2; j*j <= i; j++)
		{
			if( i%j ==0 )
			{
				flg=1;
				break;
			}
		}

		if(!flg)
		{
		  cout<<i<<endl;
			cnt++;
		}
		i++;
	}
}
int main()
{
	long long int t;
	cin>>t;
 	cout<<"The" <<t<<"primes are" <<endl;
	// generateNPrimes(t);

	cout<<" The primes upto " << t << " are " << endl;
	int k = generatePrimesToN(t);
	cout << " total prime count is "<< k << endl;

return 0;
}

