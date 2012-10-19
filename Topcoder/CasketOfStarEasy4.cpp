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
{
maxprod=0;
for(i=v.begin()+1 ; i!=(v.end()-1) ; i++)
{
	prod= *(i-1) *  *(i+1);
	if(prod > maxprod)
	{
	 maxprod=prod;
	 maxindex=i;
	}
}

total+=maxprod;
v.erase(maxindex);
}
return total;
}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
