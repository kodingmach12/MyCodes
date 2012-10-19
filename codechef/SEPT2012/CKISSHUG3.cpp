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

	#define MOD 	1000000007
    // Input macros
    #define s(n)                  scanf("%d",&n)
    #define sc(n)                 scanf("%c",&n)
    #define sl(n)                 scanf("%lld",&n)
    #define sf(n)                 scanf("%lf",&n)
    #define ss(n)                 scanf("%s",n)

	// Output Macros
	#define p(n)				  printf("%d\n",n)
	#define pnl					  printf("\n")
	
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


    /*Main code begins now */
    unsigned long long k[10000001];
	unsigned long long d = 1;
	unsigned int N;
    void preprocess(){
		k[0]=1;
		for(int i=1; i<=10000000; i++)
		{
			k[i] = k[i-1]+d;
			if(i%2)
				d*=2;		
		k[i]=k[i]%MOD;
		d=d%MOD;
		}  
    }
    void solve(){
		scanf("%d",&N);
		if(N<=10000000){			
			printf("%lld\n",k[N]);
			return;
		}
		unsigned long long k1[2]={k[9999999],k[10000000]};
//		d = 1;
//		unsigned long long k1[2]={0,1};
		for(int i=10000001; i<=N; i++){	
			k1[(i-1)%2] = k1[i%2] + d;
			k1[(i-1)%2] = k1[(i-1)%2]%MOD;
			if(i%2)
				d*=2;
			d=d%MOD;
		}
		printf("%lld\n",k1[(N-1)%2]); 
	}
	
  
    int main()
    {
    	int tcase;
    	preprocess();
		scanf("%d",&tcase);
		while(tcase--)
            solve();
        
    return 0;
    }
