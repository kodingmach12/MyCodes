#include<iostream>
#include<sstream>
using namespace std;
void solver()
{
long long int n,c1,n1,c2,n2,res[3],a,b;
cin>>n>>c1>>n1>>c2>>n2;
double rate1=(n1/c1),rate2=(n2/c2); 

if(rate1<rate2)
{
a=n;
b=0;
while(  (a%n1)!=0 && (b%n1)!=0 )
{
a-=a%n1;
b=n-a;
}
res[0]=a/n1;
res[1]=b/n1;
res[2]=res[0]*c1 + res[1]*c2;
}


cout<<endl<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
}
int main()
{
long long int tcases;
cin>>tcases;
while(tcases--)
  solver();

return 0;
}

