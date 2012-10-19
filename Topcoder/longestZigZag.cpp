#include<iostream>
#include<sstream>
#include<vector>

using namespace std;
int solver(vector<int> v)
{
int size=v.size(),i,prev,cur,nex,cnt=0;
vector<int>:: iterator itr;
for(i=0 ;i!=size-1;i++)
{
if(v[i+1]>v[i])
	v[i]=1;
else
	v[i]=0;
}
for(itr=v.begin() ;itr!=v.end();itr++)
	cout<<" "<<*itr;
cout<<endl;
prev=v[0];
cnt++;
	for(i=1;i<size-1;i++)
	{
		cur=v[i];
		if(cur!=prev)
		{
		 cnt++;
		 prev=cur;
		}
	}
cnt++;
cout<<cnt<<endl;

}
int main()
{
int tcases,el;
cin>>tcases;
vector<int> v;
while(tcases--)
{
cin>>el;
v.push_back(el);
}
  solver(v);

return 0;
}

