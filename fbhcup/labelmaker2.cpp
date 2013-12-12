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

    typedef unsigned long long               ull;
    typedef vector<int>             vi;
    typedef pair<int, int >         ii;
    typedef vector< ii >            vii;
    typedef set<int>                si;
    typedef map<string,int>         msi;

    /*Main code begins now */
    void solve(int tcase){
      ull n,sum;
      string s;

      cin>>s;
      cin>>n;

      int len = s.size();
      ull cnt[50];

      cnt[0] = len;
      sum = len;
      int i;
      for(i=1;i<50;i++){
        cnt[i] = cnt[i-1]*len;
        sum = sum + cnt[i];
        if(sum > n){
          cnt[i] -= (sum-n);
          break;
        }
      }
      // cout << i<< endl;
      // for(int i=0;i<50;i++){
        // cout<<cnt[i] << " ";
      // }
      // cout <<endl;
      ull index = cnt[i];;
      string out = "";
      for(;i>0;i--){
        out += s[(index/cnt[i-1])];
        // cout <<"i = " <<i << " index = "<<index << endl;
        index = index - cnt[i-1]*(index/cnt[i-1]);
      }
        // cout <<"i = " <<i << " index = "<<index << endl;
      out += s[index-1];

      // printf(,tcase);
      cout<<"Case #"<<tcase<<": "<<out<<endl;
    }

    int main(){
        int T;
        s(T);
        for(int i=1;i<=T;i++){
            solve(i);
        }
    return 0;
    }