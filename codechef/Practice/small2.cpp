    //Other Includes
    #include<string>
    #include<iostream>
    #include<cstring>
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


     int solve(){
        int N,M;
        cin>>N>>M;
        int b[N][M],a[N][M];
        forall(i,0,N){
            forall(i,0,M){
                cin>>b[i][j];
                a[i][j] = 100;
            }
        }

        forall(i,0,N){
            forall(j,0,M){
                int p =a[i][j];
                int rmax = a[i][j];
                for(int k=j;k<M;k++){
                    rmax =( rmax > a[i][k] ? rmax : a[i][k] );
                }
                int cmax = a[i][j]
                for(int k=j;k<M;k++){
                    cmax =( cmax > a[k][i] ? cmax : a[k][i] );
                }
                if(p <= rmax){
                    for(int k=j;k<M;k++){
                        a[i][k] = ( a[i][k] < p ? a[i][k] : p );
                    }
                }
                if(p <= cmax){
                    for(int k=j;k<M;k++){
                        a[k][i] = ( a[k][i] < p ? a[i][k] : p );
                    }
                }
            }
        }
        forall(i,0,N){
            forall(j,0,M){
                cout<<a[i][j];
            }
            cout<<endl;
        }
  }
    int main()
    {
        int tcase,i=0;
        cin>>tcase;
        while(i<tcase){
            i++;
            cout<<"Case #"<<i<<" "<<result[solve(i)]<<"\n";
        }
    return 0;
    }