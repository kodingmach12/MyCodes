// BEGIN CUT HERE

// END CUT HERE
#line 5 "MiniatureDachshund.cpp"
#include <string>
#include <vector>
#include <algorithm>

#define VI   vector<int>
#define VS  vector<string>


using namespace std;
class MiniatureDachshund {
  public:
  int maxMikan(vector <int> mikan, int weight) {
    sort(mikan.begin(),mikan.end());
    int count =0;
    for(int i=0;i<mikan.size();i++){
      if(weight+mikan[i] <= 5000){
        count++;
        weight = weight+mikan[i];
      }
    }
    return count;
  }
};
