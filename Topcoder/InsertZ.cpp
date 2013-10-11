#line 5 "InsertZ.cpp"
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class InsertZ {
	public:
	string canTransform(string init, string goal) {

    int n = init.size();
    int j = 0;
    for(int i=0; i < n;){
      while(j < goal.size() && goal[j]=='z'  ){
        j++;
      }
      // cout << goal[j] << " " << init[i] << endl;
      if(goal[j] == init[i]){  i++; j++; }
      else{ return "No"; }
    }
    return "Yes";
	}
};

// int main(){

//   string i = "opdlfmvuicjsierjowdvnx";
//   string g = "zzopzdlfmvzuicjzzsizzeijzowvznxzz";
//   InsertZ a;
//   cout << a.canTransform(i,g) << endl;
// }


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
