// BEGIN CUT HERE

// END CUT HERE
#line 5 "BinaryCode.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void decode(string p) 
{
	string  res1("0");
	string  res2("1");
//	char prev=0,cur=0,next=0,sum=0;
	string prev("0"),cur("0"),next("0"),sum("0");
	int ctr=1;
	int len=p.length(); 
for(ctr=1;ctr<=len;ctr++)
{
	sum.swap(p.at(ctr));
	cur.swap(res1.at(ctr));
	cout<<sum<<"\t"<<cur<<"\n";
	next.swap(sum-cur-prev);
	res1.insert(ctr,next);
	prev.swap(cur);

}	
cout<<res1;	
	
}


int main()
{
string message;
cin>>message;

decode(message);

return 0;
}
