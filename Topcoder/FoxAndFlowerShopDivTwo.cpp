    //Data Structure includes
    #include<vector>
    #include<stack>
    #include<set>
    #include<map>
    #include<queue>
    #include<deque>
    #include<string>

    //Other Includes
    #include<iostream>
    #include<algorithm>
    #include<cstring>
    #include<cassert>
    #include<cstdlib>
    #include<cstdio>
    #include<cmath>
    using namespace std;

    // Input macros
    #define s(n)                  scanf("%d",&n)
    #define sc(n)                 scanf("%c",&n)
    #define sl(n)                 scanf("%lld",&n)
    #define sf(n)                 scanf("%lf",&n)
    #define ss(n)                 scanf("%s",n)

    // Output Macros
    #define p(n)                  printf("%d\n",n)

    // Useful constants
    #define INF                   (int)1e9
    #define EPS                   1e-9

    // Useful hardware instructions
    #define bitcount              __builtin_popcount
    #define gcd                   __gcd


    // Useful container manipulation / traversal macros
    #define forall(i,a,b)         for(int i=a;i<b;i++)
    #define foreach(v, c)         for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
    #define all(a)                a.begin(), a.end()
    #define in(a,b)               ( (b).find(a) != (b).end())
    #define pb                    push_back
    #define fill(a,v)             memset(a, v, sizeof a)
    #define sz(a)                 ((int)(a.size()))
    #define mp                    make_pair


    // Some common useful functions
    #define checkbit(n,b)                ( (n >> b) & 1)
    #define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
    #define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

    typedef vector<int> VI;
    typedef vector<vector<int> > VVI;
    typedef long long LL;
    typedef vector<long long > VLL;
    typedef pair<int, int > PII;

 class FoxAndFlowerShopDivTwo {
	public:
	int count(vector<string> flowers,int r1,int c1,int r2,int c2)
	{
	    int cnt=0;
        for(int i=r1;i<=r2;i++)
        {   //cout<< flowers[i] << endl;
            for(int j=c1;j<=c2;j++)
            {   string str = flowers[i];
                if(str.at(j))
                    cnt++;
            }
        }
        return cnt;
	}
	int theMaxFlowers(vector <string> flowers, int r, int c) {
	    int rows=flowers.size();
	    int cols=flowers[0].size();

        int a = count(flowers,0,0,r-1,cols);
        int b = count(flowers,0,0,rows,c-1);
        int c1 = count(flowers,r+1,0,rows,cols);
        int d = count(flowers,0,c+1,rows,cols);

        int res1 = max(a,b);
        int res2 = max(c1,d);

        return max(res1,res2);
    }
};

int main()
{
    FoxAndFlowerShopDivTwo f;
    vector<string> flowers;
          string  fl[]    ={".FFF..F...",
                             "FFF...FF.F",
                             "..F.F.F.FF",
                             "FF..F.FFF.",
                             "..FFFFF...",
                             "F....FF...",
                             ".FF.FF..FF",
                             "..F.F.FFF.",
                             ".FF..F.F.F",
                             "F.FFF.FF.F" };
                    int i;
                    forall(i,0,10)
                        flowers.push_back(fl[i]);
    cout<<f.theMaxFlowers(flowers,4,3);
}
