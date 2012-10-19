// BEGIN CUT HERE

// END CUT HERE
#line 5 "MaximizeSquares.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
class MaximizeSquares {
	public:
	int squareCount(int N) {
int sqr=(int)floor(sqrt(N));
int res=(sqr)*(sqr-1)*(2*sqr-1)/6;
int rem=N-sqr*sqr;
if(rem== 0  )   return res;
if(rem<= sqr)   return res+rem*(rem-1)/2;
if(rem > sqr )  res+=sqr*(sqr-1)/2;
rem-=sqr;
return res+rem*(rem-1)/2;
		
	}
};
