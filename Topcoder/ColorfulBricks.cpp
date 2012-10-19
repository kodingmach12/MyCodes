// BEGIN CUT HERE

// END CUT HERE
#line 5 "CasketOfStar.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ColorfulBricks {
	public:
    int countLayouts(string bricks)
    {
        int len=bricks.size();
        int cnt[26]={0};
        for(int i=0;i<len;i++){
                cnt[bricks[i]-65]++;
        }
        int charcnt=0;
        for(int i=0;i<26;i++){
            if(cnt[i]>0)
                charcnt++;
        }
        if(charcnt==1)
            return 1;
        if(charcnt==2)
            return 2;
        return 0;
	}
};

int main()
{
    ColorfulBricks C;
    string s;
    int tcases;
    cin>>tcases;
    for(int i=0;i<tcases;i++){
        cin>>s;
        cout<<C.countLayouts(s)<<endl;
    }
return 0;
}
