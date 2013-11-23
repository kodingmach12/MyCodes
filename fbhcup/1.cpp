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
  #define p(n)          printf("%d\n",n)
    #define ps(n)                 printf("%s\n",n)
  #define pnl           printf("\n")

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

    typedef long long               LL;
    typedef vector<int>             vi;
    typedef pair<int, int >         ii;
    typedef vector< ii >            vii;
    typedef set<int>                si;
    typedef map<string,int>         msi;

    /*Main code begins now */
    void solve(int tcase){
        int n;
        scanf("%d",&n);
        char c;
        int grid[20][20],side = 0, si = -1, sj = -1,li = -1, lj = -1,count = 0;
        bool res = false;

        for(int i =0; i<n;i++){
          for(int j=0;j<n;j++){
            grid[i][j]=0;
            cin >> c;
            if(c=='#'){
              count++;
              grid[i][j]=1;
              if(si == -1 && sj == -1){
                si = i;
                sj = j;
                side = 1;
              }
              li = i;
              lj = j;
            }
          }
        }

        for(int j=sj+1; j < n && grid[si][j]; j++){
          side++;
        }

        if( (count!=side*side) ){
          printf("Case #%d: NO\n",tcase);
          return;
        }


        for(int i =0; i<n;i++){
          for(int j=0;j<n;j++){
              // printf("%d",grid[i][j]);
            if(grid[i][j] == 1){
              if(i>=si && i<si+side && j>=sj && j<sj+side){
                continue;
              }else{
                   printf("Case #%d: NO\n",tcase);
                   return;
              }
            }
          }
        }
        printf("Case #%d: YES\n",tcase);
    }

    int main(){
        int T;
        s(T);
        for(int i=1;i<=T;i++){
            solve(i);
        }
    return 0;
    }