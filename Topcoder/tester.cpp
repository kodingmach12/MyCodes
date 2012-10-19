#include <iostream> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cctype> 
#include <cmath> 
#include <list> 
#include <iomanip> 
#include <sstream> 
#include <algorithm> 
#include <map> 
#include <set> 
#include "FINDSTRING.cpp"
using namespace std; 

vector <string> getFiles(vector <string> f) 
{
	  vector< string > :: iterator i;
	  string cur=".",par="..";
	  //	  int len=f.size();
	  string l1=*(i.end()-1);
	  string l2=*(i.end()-2);
	  if( (l1==cur|| l1==par )  && (l2==cur ||  l2==par ))
	    return f;
		
}
int main()
{
DengklekMakingChains A;
vector<string> a;
string chain;
int len,max;
cin>>len;
while(len--){
	cin>>chain;
	a.push_back(chain);
}
max=A.maxBeauty(a);
cout<<max<<endl;
return 0;
}

