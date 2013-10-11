// BEGIN CUT HERE

// END CUT HERE
#line 5 "GUMIAndSongsDiv2.cpp"
#include <string>
#include <vector>
using namespace std;
class GUMIAndSongsDiv2 {
	public:
  bool myfunction (pair<int,int> i,pair<int,int> j) { return (i.first<j.first); }
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
    int res = 0, n = duration.size(), smallest = duration[0], sum =0 ;
    int diff[15][15];
    for(int i=0;i<n;i++){
      sum += duration[i];
      smallest = smallest > duration[i] ? duration[i] : smallest;
    }
    if(T < smallest) {
      return 0;
    }
    if(T == smallest){
      return 1;
    }
    if(T > sum){
      return n;
    }

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        diff[i][j] = (tone[i] > tone[j]) ? (tone[i]-tone[j]) : ( tone[j]-tone[i] );
      }
    }

    vector<int,int> v;
    for(int i=0;i<n; i++){
      v.push(make_pair(duration[i],tone[i]));
    }
    std::sort(v.begin(),v.end(),myfunction);




	}
};
