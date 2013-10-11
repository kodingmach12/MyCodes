// BEGIN CUT HERE

// END CUT HERE
#line 5 "GearsDiv2.cpp"
#include<iostream>
#include<string>
#include<vector>

typedef long long LL;

using namespace std;
class GearsDiv2 {
	public:
	int getmin(string d) {
		int res = 0;
    int len = d.size();
    int cnt = 1,i;

    for( i=1; i < len; i++){
      while(d[i] == d[i-1] && i<len){
        i++;
        cnt++;
      }
      if(cnt >1 ){
        res += cnt/2;
        cnt = 1;
      }
      // cout << res << endl;
    }

    i=1;
    if(  d[0] == d[len-1]){
      int start =  1, end = 1;
      while(d[i] == d[i-1] && i < len){
        start++;
        i++;
      }
      i = len-2;
      while(d[i] == d[i+1] && i > -1){
        end++;
        i--;
      }

      if( start%2 == 0 ||  end%2 ==0){
        ;
      }else{
        res++;
      }
    }
    return res;
	}
};
// int main(){
//   GearsDiv2 a;
//   string s;
//   cin>>s;
//   cout<<a.getmin(s);

// return 0;
// }