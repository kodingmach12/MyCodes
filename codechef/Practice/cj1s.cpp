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


    /*Main code begins now */

    void solve(int tcase){
        char a[4][4];
        int resi=-1,x = 0, o=0,i,j,ti=-1,tj=-1;
        bool awon = false, bwon = false, empty = false;

        char* result[4] = {"X won", "O won", "Draw","Game has not completed" };

        for( i=0;i<4;i++){
            for( j=0;j<4;j++){
                cin>>a[i][j];
                if(a[i][j] == '.'){
                    empty = true;
                }
                else if(a[i][j] == 'T'){
                    ti = i,tj = j;
                }
            }
        }

        if( ti!=-1 && (ti==tj || ti+tj==3) ){  a[ti][tj] = 'X'; }

        if(a[0][0] == a[1][1]  &&  a[1][1] == a[2][2] && a[2][2] == a[3][3]){
            if(a[0][0] == 'X'){ resi = 0;}
            else if(a[0][0] == 'Y'){ resi = 1;}
        }
        if(a[0][3] == a[1][2]  &&  a[1][2] == a[2][1 ] && a[2][1] == a[3][0]){
            if(a[0][0] == 'X'){ resi = 0;}
            else if(a[0][0] == 'Y'){ resi = 1;}
        }
        if( ti!=-1 && (ti==tj || ti+tj==3) ){
              a[ti][tj] = 'Y';
            if(a[0][0] == a[1][1]  &&  a[1][1] == a[2][2 ] && a[2][2] == a[3][3]){
                if(a[0][0] == 'X'){ resi = 0;}
                else if(a[0][0] == 'Y'){ resi = 1;}
            }
            if(a[0][3] == a[1][2]  &&  a[1][2] == a[2][1 ] && a[2][1] == a[3][0]){
                if(a[0][0] == 'X'){ resi = 0;}
                else if(a[0][0] == 'Y'){ resi = 1;}
            }
        }
        if( ti != -1) { a[ti][tj] = 'T'; }

        if( resi != -1){
            printf("Case #%d: %s\n",tcase,result[resi]);
            return;
        }

        for( i=0;i<4;i++){
            x = 0, o =0;
            for( j=0;j<4;j++){
                if(a[i][j] == 'X'){ x++;}
                else if(a[i][j] == 'O'){ o++;}
                else if(a[i][j] == 'T'){
                    x++;
                    o++;
                 }
            }
            if(x == 4 ){ resi =0; }
            else if(o == 4 ){ resi =1; }
        }
        if( resi == -1 && !empty){ resi = 2; }
        if( resi != -1){
            printf("Case #%d: %s\n",tcase,result[resi]);
            return;
        }

        for(int i=0;i<4;i++){
            x = 0, o =0;
            for(int j=0;j<4;j++){
                if(a[j][i] == 'X'){ x++;}
                else if(a[j][i] == 'O'){ o++;}
                else if(a[j][i] == 'T'){
                    x++;
                    o++;
                 }
            }
            if(x == 4 ){ resi =0; }
            else if(o == 4 ){ resi =1; }
        }
        if(resi == -1 && empty ){ resi = 3; }
        printf("Case #%d: %s\n",tcase,result[resi]);
	}
    int main()
    {
    	int tcase,i=0;
		scanf("%d",&tcase);
		while(i<tcase){
            solve(i);
            i++;
        }
    return 0;
    }
