// BEGIN CUT HERE

// END CUT HERE
#line 5 "JumpFurther.cpp"
#include<string>
#include<vector>
#include<iostream>

using namespace std;
class JumpFurther {
	public:
	int furthest(int N, int badStep) {
    int res = (N*(N+1))/2;
    for (int i = 0; i < N+1; ++i)
    {
      if(i*i == badStep)
        res -= 1;
    }
    return res;
	}
};
