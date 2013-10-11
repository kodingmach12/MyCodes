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
    #define ps(n)         printf("%s\n",n)
    #define pnl           printf("\n")

    // Useful constants
    #define INF                   (int)1e9
    #define EPS                   1e-9

    // Useful hardware instructions
    #define bitcount              __builtin_popcount
    #define gcd                   __gcd


    // Useful container manipulation / traversal macros
    #define forall(i,a,b)         for(int i=a;i<b;i++)
    #define forallrev(i,a,b)      for(int i=a;i>=b;i--)
    #define foreach(v, c)         for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
    #define all(a)                a.begin(), a.end()
    #define in(a,b)               ( (b).find(a) != (b).end())
    #define pb                    push_back
    #define fill(a,v)             memset(a, v, sizeof a)
    #define sz(a)                 ((int)(a.size()))
    #define mp                    make_pair
    #define maX(a,b)                    (a>b?a:b)
    #define miN(a,b)                    (a<b?a:b)


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

    char in[500][500];
    int L[500][500], R[500][500],T[500][500],B[500][500];
    int p[95] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,  59,  61,  67,  71,
                 73,  79,  83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
                419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499 };
    int row,col,res;

    void printL(){
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                /* code */
                printf("%d ",L[i][j]);
            }
            printf("\n");
        }
    }
    void printR(){
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                /* code */
                printf("%d ",R[i][j]);
            }
            printf("\n");
        }
    }
    void printT(){
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                /* code */
                printf("%d ",T[i][j]);
            }
            printf("\n");
        }
    }
    void printB(){
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                /* code */
                printf("%d ",B[i][j]);
            }
            printf("\n");
        }
    }

    void preprocess(){
        forall(i,0,row)
            L[i][0]=0;
        forall(i,0,row)
            R[i][col-1]=0;
        forall(i,0,col)
            T[0][i]=0;
        forall(i,0,col)
            B[row-1][i]=0;

        forall(i,0,row){
            forall(j,1,col){
                if(in[i][j]=='#')
                    L[i][j]=0;
                else{
                    if(in[i][j-1]=='#')
                        L[i][j]=0;
                    else
                        L[i][j] = L[i][j-1]+1;
                }
            }
        }

        forall(i,1,row){
            forall(j,0,col){
                if(in[i][j]=='#')
                    T[i][j]=0;
                else{
                    if(in[i-1][j]=='#')
                        T[i][j]=0;
                    else
                        T[i][j] = T[i-1][j] + 1;
                }
            }
        }


        forall(i,0,row){
            forallrev(j,col-2,0){
                if(in[i][j]=='#')
                    R[i][j]=0;
                else{
                    if(in[i][j+1]=='#')
                        R[i][j]=0;
                    else
                        R[i][j] = R[i][j+1]+1;
                }
            }
        }

        forallrev(i,row-2,0){
            forall(j,0,col){
                if(in[i][j]=='#')
                    B[i][j]=0;
                else{
                    if(in[i+1][j]=='#')
                        B[i][j]=0;
                    else
                        B[i][j] = B[i+1][j]+1;
                }
            }
        }

        // cout<<"left\n";
        // printL();
        // cout<<"right\n";
        // printR();
        // cout<<"top\n";
        // printT();
        // cout<<"bottom\n";
        // printB();
    }

    int countGhosts(int r, int c){
        int res = miN( miN(L[r][c],R[r][c]),miN(T[r][c],B[r][c]) );
        int cnt = 0;
        for(int i=0; i<95;i++){
            if(res >= p[i]){
                // cout<<"row is "<<r<<" col is "<<cc << endl;
                // cout<<res<<endl;
                cnt++;
            }else
                break;
        }
        return cnt;
    }

    void solve(){
        res = 0;
        cin >> row >> col;
        // cout << " row count is " << row << " col count is " << col << endl;
        for (int i = 0; i < row; ++i)
        {
            /* code */
            for (int j = 0; j < col; ++j)
            {
                /* code */
                cin >> in[i][j];
            }
        }
        // for (int i = 0; i < row; ++i)
        // {
        //     /* code */
        //     for (int j = 0; j < col; ++j)
        //     {
        //         /* code */
        //         cout << in[i][j];
        //     }
        //     printf("\n");
        // }

        preprocess();
        for (int i = 0; i < row; ++i)
        {
            /* code */
            for (int j = 0; j < col; ++j)
            {
                /* code */
                if(in[i][j] != '#')
                    res += countGhosts(i,j);
            }
        }
        // cout << row << col << endl;
        cout << res << endl;
    }

    int main(){
        int tcase;
        cin>>tcase;
        for (int i = 0; i < tcase; ++i)
        {
            /* code */
            solve();
        }
    return 0;
    }