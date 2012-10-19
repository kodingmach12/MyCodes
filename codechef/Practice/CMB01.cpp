#include<iostream>
using namespace std;
int reverse(int n)
{
int temp=0;
while(n)
{
temp=temp*10+n%10;
n/=10;
//cout<<temp<<endl;
}
return temp;
}
void solver()
{
int n1,n2,final;
cin>>n1>>n2;
//cout<<" n1: "<<n1<<" n2:  "<<n2<<endl;
n1=reverse(n1);
n2=reverse(n2);
//cout<<" n1: "<<n1<<" n2:  "<<n2<<endl;
final=n1+n2;
final=reverse(final);
cout<<final<<endl;

}
int main()
{
int tcases;
cin>>tcases;
while(tcases--)
	solver();


}

