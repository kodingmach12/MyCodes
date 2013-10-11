// BEGIN CUT HERE

// END CUT HERE
#line 5 "GooseTattarrattatDiv2.cpp"
#include<string>
#include<vector>

typedef long long LL;

using namespace std;
class GooseTattarrattatDiv2 {
	public:
	int getmin(string s) {

    int len = s.size();
    int hash[26];
    for(int i=0;i<26;i++){
      hash[i] = 0;
    }
    int max = 0;
    for(int i=0;i<len;i++){
      hash[s[i]-97]++;
    }
    for(int i=0;i<26;i++){
      if( max < hash[i] )
          max = hash[i];
    }
    return len-max;
	}
};

int GooseTattarrattatDiv2:getmin(string S)
{
    int n = S.length(), m = 0;
    for (char ch : S) {  // For each letter in S
        // Count the number of times it appears
        int c = 0;
        for (int i=0; i<n; i++) {
            if (S[i] == ch) {
                c++;
            }
        }
        // remember the maximum
        m = std::max(m, c);
    }
    return n - m;
}