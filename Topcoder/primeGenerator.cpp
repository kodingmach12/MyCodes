#include<iostream>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
void solver(long long int n)
{

long long int i=2,cnt=0,j,k;
int flg=0;

while(cnt<n)
{
	flg=0;
for(j=2;j<=sqrt(i);j++)
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
solver(t);

return 0;
}

