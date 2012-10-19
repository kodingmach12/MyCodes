// BEGIN CUT HERE

// END CUT HERE
#line 5 "DengklekMakingChains.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class DengklekMakingChains {
	public:
int maxBeauty(vector <string> c) 
{
	vector< string >:: iterator i;
	int left=0,mid=0,right=0,maxl=0,maxr=0,sin=0,maxsin=0,corner=0,maxcorner=0;
	string chain;
for(i=c.begin();i!=c.end();i++) 
{	
	left=0;
	sin=0;
	right=0;  	
	chain= (*i);
if(chain.at(0)=='.' && isdigit(chain.at(2)) ){
	if(isdigit(chain.at(1)))
		left+=chain.at(1)-'0' ;
	left+=chain.at(2)-'0';
	if(left>maxl)
		maxl=left;  }
else if(chain.at(0)=='.' && chain.at(2)=='.') {
	if(isdigit(chain.at(1)))
		sin=chain.at(1)-'0';	
	if(sin>maxsin)
		maxsin=sin;	}
else if( isdigit(chain.at(0)) && isdigit(chain.at(1)) && isdigit(chain.at(2)) )  {
	mid+=chain.at(0)-'0';  mid+=chain.at(1)-'0';  mid+=chain.at(2)-'0';
}
else if(isdigit(chain.at(0))  && chain.at(2)=='.' )  {
	if(isdigit(chain.at(1))) right+=chain.at(1)-'0';
	right+=chain.at(0)-'0';
if(right>maxr) 	maxr=right;
}
else if(isdigit(chain.at(0))  && chain.at(1)=='.' && isdigit(chain.at(2))  )  {
corner+=chain.at(0) - '0' + chain.at(2) -'0';
if
}
cout<<chain<<" L "<<left<<" M "<<mid<<" R "<<right<<" Single "<<maxsin<<endl;
}
int tot=maxl+mid+maxr;
int final= (tot > maxsin ? tot : maxsin);
cout<<chain<<" L "<<maxl<<" M "<<mid<<" R "<<maxr<<" Single "<<maxsin<<endl;
return final;
}
};
int main()
{

 DengklekMakingChains A;
 vector<string>v;
 int n;
 string s;
 cin>>n;
 while(n--)
{
cin>>s;
v.push_back(s);
}
int res=A.maxBeauty(v);
cout<<endl<<res<<endl;
return 0;
}
