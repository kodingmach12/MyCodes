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
   	int in[100][100],T;
   	bool cmprow(int r1, int r2){
   		bool res = true;
		for(int j=0;j<T && res;j++)
			if( in[r1][j] != in[r2][j] )
				res = false;
   		return res;
   	}
   	bool compare(int row){
   		bool res = true;
		for(int i=0;i<T && res;i++){
			res = cmprow(row,i);
			if( (!res && !in[row][i]) || (res && in[row][i]) )
				res = true;
			else
				res = false;
		}
		return res;
   	}

    void solve(){
		s(T);
    	string s;
    	forall(i,0,T)
    		forall(j,0,T){
				cin>>s;
				if(s=="NO")
					in[i][j] = 0;
				else 
					in[i][j] = 1;    		
    		}
    	int outrow=0;
    	bool found = false;
    	for(int i=0;i<T;i++){
			if(in[i][i]){
				found = compare(i);
				if(found==true){
					outrow = i;
					break;
				}
			}
    	}
    	if(found){
			for(int i=0;i<T;i++){
				if(in[outrow][i])	
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
		else
			for(int i=0;i<T;i++)
				printf("NO\n");
    }
    int main(){
          solve();          
    return 0;
    }
