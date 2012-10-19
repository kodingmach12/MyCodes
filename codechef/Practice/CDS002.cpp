#include<iostream>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;
void solver()
{
  long int n,res=1;
  int i,j;
  cin>>n;
  res=pow(2,2*n);
  
  res--;
  res*=n;
  res++;
  for(i=0;i<n;i++)
    {
      cout<<res<<endl;
      res*=(n);
      res/=(n-1);
      res+=1;
    }
  cout<<res<<endl;
}
int main()
{
int tcases;
cin>>tcases;
while(tcases--)
  solver();

return 0;
}

