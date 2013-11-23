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
    void solve(){
        int N,res = 0;
        s(N);
        int h[50],d[50],dsum =0,hsum=0;
        for (int i = 0; i < N; ++i){
            s(h[i]);
            hsum += h[i];
        }
        for (int i = 0; i < N; ++i){
            s(d[i]);
            dsum += d[i];
        }

        int incr = (dsum-hsum);
        int stepIncr = N-2;
        
        int eqcnt = 0;
        for(int i=0; i<N; i++){
            if(h[i] == d[i]){
                eqcnt++;
            }
        }
        if(eqcnt == N){
            printf("0\n");
            return;
        }


        //handle case of -ve stepIncr i.e. single element
        if(stepIncr < 0 ){
            if(incr > 0 ){
                res = -1;
            }
            else{
                res = abs(incr);
            }
        }
        else if(stepIncr == 0 ){    // case of 2 elements
            if(incr != 0){
                res = -1;
            }else{
                res = abs(d[0]-h[0]);       
            }
        }
        else {
            // not possible scenario
            if( incr%stepIncr != 0 || incr <= 0){
              res = -1;
            }else{
                int steps = incr/stepIncr;
                for (int i = 0; i < N; ++i){
                    int thisIncr = d[i]-h[i];
                    if( ((steps+thisIncr)%2 == 0) && ((steps-thisIncr)%2 == 0) )
                    {
                        res = steps;
                    }
                    else{
                        res = -1;
                        break;
                    }
                }
            }
        }
        printf("%d\n",res);
    }

    int main(){
        int T;
        s(T);
        for(int i=0;i<T;i++){
            solve();            
        }
    return 0;
    }