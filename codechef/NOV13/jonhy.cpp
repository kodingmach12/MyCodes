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
    #define ps(n)                 printf("%s\n",n)
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
unsigned long long countOccurence(char* src,int slen, char* pat){
// ps(src);
// ps(pat);

// p(slen);
int plen  = 0;
int si=0,pi=0;
unsigned long long sh=0,ph=0,count = 0;
while(*(pat+plen)!='\0'){
    ph = ph + *(pat+plen);
    sh = sh + *(src+plen);
    plen++;
    // p(sh);
    // p(ph);
    // p(plen);
}
if(sh == ph){
    if(0 == memcmp(src,pat,plen)){
        count++;
    }
}
si = plen;
while( si <= slen ){
    sh = sh + *(src+si) - *(src+si-plen);
    si++;
    // p(sh);
    // p(ph);
    if(sh == ph && 0 == memcmp(src+si-plen,pat,plen) ){
            count++;
    }
}
return count;
}

unsigned long long getOccurence(char* src, char* pat){
int prevDash = -1;
int slen = 0;
int plen = strlen(pat);
unsigned long long count = 0;
while( *(src+slen) != '\0' ){
    if(src[slen] == '-'){
        if(slen - prevDash >= plen){
            count+= countOccurence(src+(prevDash+1),slen-(prevDash+1),pat);
        }
        prevDash = slen;
    }
    slen++;
}
if(slen - prevDash >= plen){
    count+= countOccurence(src+(prevDash+1),slen-(prevDash+1),pat);
}
return count;
}

void solve(){

int w,n;
scanf("%d",&w);
char parr[500][5000];

for(int i =0 ; i < w; i++ )
scanf("%s",parr[i]);

scanf("%d",&n);
char sarr[100][50000];

for(int i =0 ; i < n; i++ )
scanf("%s",sarr[i]);

unsigned long long count;
for(int i =0 ; i < w ; i++ ){
 count = 0;
for(int j =0; j < n; j++){
    count += getOccurence(sarr[j],parr[i]);
}
printf("%lld\n",count);
}
}

int main()
{
  solve();
    // char a[100],b[100];
    // scanf("%s",a);
    // scanf("%s",b);
    // printf("%d",countOccurence(a,b));
return 0;
}
