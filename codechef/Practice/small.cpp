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


    /*Main code begins now */
    int checkArr(char* a[][4]){
        forall(i,0,4){
            if( (a[i][0]==a[i][1]) && (a[i][1]==a[i][2]) && (a[i][2]==a[i][3]) ){
                if(a[i][0]=='X'){ return 0;}
             return 1;
            }
        }
        forall(i,0,4){
            if( (a[0][i]==a[1][i]) && (a[1][i]==a[2][i]) && (a[2][i]==a[3][i]) ){
                if(a[0][i]=='X'){ return 0;}
             return 1;
            }
        }
        if( (a[0][0]==a[1][1]) && (a[1][1]==a[2][2]) && (a[2][2]==a[3][3]) ){
                if(a[0][0]=='X'){ return 0;}
             return 1;
        }
        if( (a[0][3]==a[1][2]) && (a[1][2]==a[2][1]) && (a[2][1]==a[3][0]) ){
                if(a[0][3]=='X'){ return 0;}
             return 1;
        }
        return -1;
    }

    void solve(int tcase){
        char a[4][4];
        int cnt;
        int resi=-1,xcnt = 0, ocnt=0,ti=-1,tj=-1;
        bool awon = false, bwon = false, empty = false;

        string result[4] = {"X won", "O won", "Draw","Game has not completed" };

        forall(i,0,4){
            xcnt = ocnt = 0;
            forall(j,0,4){
                cin>>a[i][j];
                if(a[i][j] == '.'){ empty = true;  }
                if(a[i][j] == 'X'){ xcnt++;  }
                if(a[i][j] == 'O'){ ocnt++;  }
                else if(a[i][j] == 'T'){ ti = i,tj = j; }
            }
            cnt = (xcnt > ocnt ? xcnt : ocnt);
            cout<<cnt<<" ";
            if(cnt == 4 || (cnt ==3  && ti == i) ){
                if(xcnt >ocnt){ resi = 0;}
                else  resi = 1;
            }
        }
        if( resi == -1 && !empty){ resi = 2; }
        if( resi != -1){
            cout<<"Case #"<<tcase<<" "<<result[resi]<<"\n";
            return;
        }

        forall(j,0,4){
            xcnt = ocnt = 0;
            forall(i,0,4){
                if(a[i][j] == 'X'){ xcnt++;  }
                if(a[i][j] == 'O'){ ocnt++;  }
            }
            cnt = (xcnt > ocnt ? xcnt : ocnt);
            cout<<cnt<<" ";
            if( cnt==4 || ( cnt==3  && tj==j) ){
                if(xcnt >ocnt){ resi = 0;}
                else  resi = 1;
            }
        }
        if( resi != -1){
            cout<<"Case #"<<tcase<<" "<<result[resi]<<"\n";
            return;
        }
        xcnt = ocnt = 0;
        forall(i,0,4){
            if(a[i][i] == 'X'){ xcnt++;  }
            if(a[i][i] == 'O'){ ocnt++;  }
        }
            cnt = (xcnt > ocnt ? xcnt : ocnt);
            cout<<cnt<<" ";
            if( cnt==4 || ( cnt==3  && (ti==tj) ) ){
                if(xcnt >ocnt){ resi = 0;}
                else  resi = 1;
            }

        if( resi != -1){
            cout<<"Case #"<<tcase<<" "<<result[resi]<<"\n";
            return;
        }
        xcnt = ocnt = 0;
        for(int i=0,j=3; i<4 ;i++,j--){
                if(a[i][j] == 'X'){ xcnt++;  }
                if(a[i][j] == 'O'){ ocnt++;  }
        }
            cnt = (xcnt > ocnt ? xcnt : ocnt);
            cout<<cnt<<" ";
            if( cnt || ( cnt==3  && (ti+tj)==3 ) ){
                if(xcnt >ocnt){ resi = 0;}
                else  resi = 1;
            }

        if(resi == -1 && empty ){ resi = 3; }
        cout<<"Case #"<<tcase<<" "<<result[resi]<<"\n";
  }
    int main()
    {
      int tcase,i=0;
    scanf("%d",&tcase);
    while(i<tcase){
            i++;
            solve(i);
        }
    return 0;
    }
