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
    class player{
    public:
      string name;
      int shot;
      int height;
      int time;
    };
    vector<player> in,t1,t2,p1,p2;
    int n,m,p,res = 0;

    void print(){
        forall(i,0,n){
          cout <<in[i].name <<" "<<in[i].shot << " " << in[i].height << endl;
        }
    }

    bool comparator(player a, player b){
      if(a.shot > b.shot){  return true; }
      else if( a.shot == b.shot && a.height > b.height ){ return true; }

      return false;
    }

    bool printComparator(player a,player b){
      return ( (a.name).compare(b.name) < 0 );
    }

void solve(int tcase){
    s(n); s(m); s(p);

    forall(i,0,n){
      player p;
      cin>>p.name;
      cin>>p.shot;
      cin>>p.height;
      in.push_back(p);
    }
    sort(in.begin(),in.end(),comparator);

    forall(i,0,n){
      if(i%2)
        t1.push_back(in[i]);
      else
        t2.push_back(in[i]);
    }

forall(i,0,m){

}


    if(n == 2*p){
      printf("\n\nCase #%d: \n",tcase);
      return;
    }
    print();
}

int main(){
    int T;
    s(T);
    for(int i=0;i<T;i++){
        solve(i);
    }
return 0;
}