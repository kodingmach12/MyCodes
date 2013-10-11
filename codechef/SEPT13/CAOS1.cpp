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
    // void printL(){
    //     for (int i = 0; i < row; ++i)
    //     {
    //         for (int j = 0; j < col; ++j)
    //         {
    //             /* code */
    //             printf("%d ",L[i][j]);
    //         }
    //         printf("\n");
    //     }
    // }
    // void printR(){
    //     for (int i = 0; i < row; ++i)
    //     {
    //         for (int j = 0; j < col; ++j)
    //         {
    //             /* code */
    //             printf("%d ",R[i][j]);
    //         }
    //         printf("\n");
    //     }
    // }
    // void printT(){
    //     for (int i = 0; i < row; ++i)
    //     {
    //         for (int j = 0; j < col; ++j)
    //         {
    //             /* code */
    //             printf("%d ",T[i][j]);
    //         }
    //         printf("\n");
    //     }
    // }
    // void printB(){
    //     for (int i = 0; i < row; ++i)
    //     {
    //         for (int j = 0; j < col; ++j)
    //         {
    //             /* code */
    //             printf("%d ",B[i][j]);
    //         }
    //         printf("\n");
    //     }
    // }

    // void preprocess(){

    //     for (int i = 0; i <= row; ++i){
    //                 L[i][0] = T[i][0]  = 0;
    //     }
    //     for (int i = 0; i <= col; ++i){
    //                 L[0][i] = T[0][i]  = 0;
    //     }

    //     for (int i = 1; i <= row; ++i){
    //         for (int j = 1; j <= col; ++j)
    //         {
    //             if(in[i-1][j-1] == '#'){
    //               L[i][j] = T[i][j] = 0;
    //             }else{
    //                 L[i][j] = L[i][j-1] + 1;
    //                 T[i][j] = T[i-1][j] + 1;
    //             }

    //         }
    //     }

    //     for (int i = 0; i <= row; ++i){
    //                  R[i][col]  = B[i][col] = 0;
    //     }
    //     for (int i = 0; i <= col; ++i){
    //                  R[row][i]  = B[row][i] = 0;
    //     }

    //     for (int i = row; i >= 0; --i){
    //         for (int j = col; j >= 0; --j)
    //         {
    //             if(in[i-1][j-1] == '#'){
    //                 R[i][j]  = B[i][j] = 0;
    //             }else{
    //                 R[i][j] = R[i][j+1] + 1;
    //                 B[i][j] = B[i+1][j] + 1;
    //             }
    //         }
    //     }
    //     cout<<"left\n";
    //     printL();
    //     cout<<"right\n";
    //     printR();
    //     cout<<"top\n";
    //     printT();
    //     cout<<"bottom\n";
    //     printB();

    // }
    char in[50][50];
    int L[51][51], R[51][51],T[51][51],B[51][51];
    int p[15] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int row,col,res;

    int countGhosts(int r, int c){
        int left = 0;
        for(int i=r,j=c-1; j>=0 ; j--){
            if( in[i][j] == '^' )
                left++;
            else
               break;
        }
        int right = 0;
        for(int i=r, j= c+1; j<col; j++){
            if( in[i][j] == '^' )
                right++;
            else
                break;
        }
        int top = 0;
        for(int i=r-1,j=c; i>=0; i--){
            if(in[i][j] == '^' )
                 top++;
            else
             break;
        }
        int bottom = 0;
        for(int i=r+1,j=c; i<row; i++){
            if(in[i][j] == '^')
                bottom++;
            else
             break;
        }
        int res = miN( miN(left,right),miN(top,bottom) );
        int cnt = 0;
        // cout << left <<"  "<< right<< "  " << top<< " " << bottom <<endl;

        for(int i=0; i<15;i++){
            if(res >= p[i]){
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

        // // preprocess();
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