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

     // STL output functions
         template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){
        return os << "(" << p.first << ", " << p.second << ")";
    }

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v){
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++){
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v){
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }

    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii){
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }

    /*Main code begins now */
    int a[1000001];
	void preprocess(){
		memset(a,0,sizeof(a));
		for(int i=1;i<1000;i++){
			a[i*i]=i;
			if(i*i > 1000000)		
				break;
		}
		int prev=a[1];
		for(int i=2;i<=1000000;i++){
			if(a[i])	prev=a[i];
			a[i]=prev;
		}
	}

//    int sqroot(int n){
//		int low = 1000, high =n/2,mid,n1;
//		while(low<=high){
//			mid = low+ (high-low)/2;
//			n1 = mid*mid ;
//			if( (mid-1)*(mid-1)<n && (mid+1)*(mid+1) > n)
//				return mid;
//			else if(n1 < n)
//				low = mid +1;
//			else
//				high = mid -1;
//		}
//    }

    void solve(){
		int n;
		s(n);
		int res =0;
		res = (n<=1000000)?a[n]:sqrt(n);
		printf("%d\n",res);
	}
	
    int main()
    {
    	int n;
    	int tcase;
		scanf("%d",&tcase);
		preprocess();
		while(tcase--)
            solve();
    return 0;
    }
