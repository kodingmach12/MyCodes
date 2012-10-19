// BEGIN CUT HERE

// END CUT HERE
#line 5 "CasketOfStar.cpp"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class FoxAndFlowerShopDivTwo {
	public:
	int theMaxFlowers(vector <string> flowers, int r, int c){
	    int rows=flowers.size();
	    int cols=flowers[0].size();
	    int dp[rows][cols];
	    memset(dp,0,sizeof(dp));
        int maxval=0;
	    for(int i=0;i<r;i++)
            for(int j=0;j<cols;j++)
            {
                if(flowers[i].at(j)=='F')
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]) + 1;
                else
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j]>maxval)
                    maxval=dp[i][j];
            }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<rows;i++)
            for(int j=0;j<c;j++)
            {
                if(flowers[i].at(j)=='F')
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]) + 1;
                else
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j]>maxval)
                    maxval=dp[i][j];
            }

        memset(dp,0,sizeof(dp));

        for(int i=r+1;i<rows;i++)
            for(int j=0;j<cols;j++)
            {
                if(flowers[i].at(j)=='F')
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]) + 1;
                else
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j]>maxval)
                    maxval=dp[i][j];
            }

        memset(dp,0,sizeof(dp));

        for(int i=0;i<rows;i++)
            for(int j=c+1;j<cols;j++)
            {
                if(flowers[i].at(j)=='F')
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]) + 1;
                else
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j]>maxval)
                    maxval=dp[i][j];
            }

    return maxval;
	}

};
