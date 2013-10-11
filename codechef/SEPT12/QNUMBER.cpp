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
    LL  N;
	LL  divisors(LL num)
	{
		if(num <= 2)
			return num;
	    LL count = 0,low=1,up=num;
	    LL lim = sqrt(num);
	    for( ;low<=lim;  low++)
	        if( (num%low)==0){
                count+=2;
                up=num/low;
                if(low==up)
                    count--;
            }
	    return count;
	}
	void solve()
	{
        LL T,K,temp;
        scanf("%lld%lld",&T,&K);
        if(T==1)
        {
            temp = gcd(N,K);
//			printf("Case 1 : %lld %lld \t",N,temp);
            printf("%lld\n",divisors(temp));
        }
        else if(T==2)
        {
            if( 0==N%K){
                temp = (N/K);
                printf("%lld\n",divisors(temp));
            }
            else
                printf("0\n");
        }
        else if(T==3)
        {
            temp = 0;
            if(0==N%K)
                temp = N/K;

            LL res=divisors(N)-divisors(temp);
            printf("%lld\n",res);
        }

	}
    int main()
    {
    	LL  Q;
		scanf("%lld",&N);
        scanf("%lld",&Q);
        //printf("total divisors of %lld are %lld \n",K,divisors(K));
           while(Q--)
                solve();

    return 0;
    }
