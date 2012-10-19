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
vector<int>::const_iterator mini = min_element(v.begin(), v.end());
vector<int>::const_iterator maxi = max_element(v.begin(), v.end());
int min = *mini;
int max = *maxi;
int total= v.size();
return  (max-min+1-total);
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
