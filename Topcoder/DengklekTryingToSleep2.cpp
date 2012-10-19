// BEGIN CUT HERE

// END CUT HERE
#line 5 "DengklekTryingToSleep.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class DengklekTryingToSleep {
	public:
	int minDucks(vector <int> v)
 {
//		sort(ducks.begin(),d.end());
vector<int>::const_iterator mini = min_element(v.begin(), v.end());
vector<int>::const_iterator maxi = max_element(v.begin(), v.end());
int min = *mini;
int max = *maxi;
int total= v.size();
return  (max-min+1-total);
	}
};
int main()
{
 DengklekTryingToSleep  A;
 vector< int > v;
 int total;
 int elem;
 cin>>total;
 while(total--)
 {
 cin>>elem;
  v.push_back(elem);
 }
int left=A.minDucks(v);
cout<<endl<<left<<endl;

return 0;
}
