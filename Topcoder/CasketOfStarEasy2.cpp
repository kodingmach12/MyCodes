// BEGIN CUT HERE

// END CUT HERE
#line 5 "CasketOfStarEasy.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class CasketOfStarEasy {
	public:
int maxEnergy(vector <int> v) {
int prod=1,maxprod=0,total=0;
vector<int>::iterator i;
vector<int>::iterator maxindex;
while( v.size()!=2 )
{ maxprod=0;
for(i=v.begin()+1 ; i!=(v.end()-1) ; i++)
{
	prod= *(i-1) *  *(i+1);
cout<<prod<<" ";
	if(prod > maxprod)
	{
	 maxprod=prod;
	 maxindex=i;
	}
        else if( prod == maxprod)
        {
         if(*i < *maxindex)
		maxindex=i;
	}
}
total+=maxprod;
v.erase(maxindex);
cout<<endl;
for(i=v.begin() ; i!=v.end() ; i++)
{
  cout<<*i<<" ";
}
cout<<endl<<" Maxprod : "<<maxprod<<" total :"<<total<<endl;
}
return total;
}
};
int main()
{
CasketOfStarEasy A;
vector<int> v;
int n,elem;
cin>>n;
	while(n--)
	{
		cin>>elem;
		v.push_back(elem);
	}
int tot=A.maxEnergy(v);
cout<<endl<<tot<<endl;
return 0;
}
