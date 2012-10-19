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

    // Output macros
    #define p(n)				  printf("%d\n",n)
    #define pnl					  printf("\n")

    // Input macros
    #define s(n)                  scanf("%d",&n)
    #define sc(n)                 scanf("%c",&n)
    #define sl(n)                 scanf("%lld",&n)
    #define sf(n)                 scanf("%lf",&n)
    #define ss(n)                 scanf("%s",n)

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
    void solve(){
    	int N;
    	char s[1001];
		scanf("%s",s);
		int len=strlen(s);
		int ins=1;
		int i=1;
		while( i<len){
		int change =s[i]-s[i-1];
		change = (change>=0) ? change : (26+change);
//		printf("%c %c %d\n",s[i-1],s[i],change);
			ins += change;
			i++;
		}
		ins += len;
		if(ins<=11*len)
			printf("YES\n");
		else
			printf("NO\n");
//		printf("%d %d\n",ins,len);
	}
    int main(){
    	int tcase;
    	s(tcase);
		for(int i=0;i<tcase;i++)
            solve();          
    return 0;
    }
