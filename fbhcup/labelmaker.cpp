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

    typedef unsigned long long               ull;
    // typedef uint64_t               ull;

    typedef vector<int>             vi;
    typedef pair<int, int >         ii;
    typedef vector< ii >            vii;
    typedef set<int>                si;
    typedef map<string,int>         msi;

    /*Main code begins now */

    void printArr(ull arr[], int size){
      for (int i = 0; i < size; ++i)
      {
        cout<<" " << arr[i];
      }
      cout<<endl;
    }

    void solve(int tcase){
      ull n,nc,cnt[51],sum[51],wordindex[51];
      string s,out="";
      cin>>s;
      cin>>n;

      int len = s.size(),wordlen=0;
      cnt[0] = 1;
      sum[0] = len;
      for(int i=1;i<51;i++){
        // cout<< " i is "<< i <<" cnt is " << cnt[i-1];
        cnt[i] = cnt[i-1]*len;
        // cout<<" "<<cnt[i];
        if( cnt[i] == 0 ) {
          // cout << endl << " inside cnt 0 " << endl;
          sum[i] = n-sum[i-1];
          // cout<<" sum is "<<sum[i]<<endl;
          n =  sum[i]-1;
          wordindex[i] = 1;
          wordlen = i-1;

          break;
        }
        sum[i] = sum[i-1] + len*cnt[i];
        // cout<<" sum is "<<sum[i]<<endl;
        if(sum[i] == n) {
          wordlen = i;
          break;
        }
        if(sum[i]>n){
          wordlen = i;
          break;
        }
      }

      if(!wordlen){
        while(sum[wordlen]<n){
          wordlen++;
        }
      }

      // printArr(cnt,51);
      // printArr(sum,51);
      // cout<<" wordlen is "<<wordlen<<endl;

      for(int i=wordlen;i>0;i--){
        int j = 1;
        // cout << " n is " << n << " wordindex["<<i<<"] is "<< wordindex[i]<< "  j is " << j << endl;
        while ( (n - cnt[i]*j) > sum[i-1] ){
                    j++;
                    // cout << j << " " <<endl;
                    // if(j > len){
                      // break;
                    // }
        }

        n = n - cnt[i]*j;
        wordindex[i] = j;
        // cout << " n is " << n << " wordindex["<<i<<"] is "<< wordindex[i]<< "  j is " << j << endl;
      }
      wordindex[0] = n;
      for (int i = wordlen; i >=0 ; i--)
      {
        out += s[wordindex[i]-1];
      }
      // printArr(wordindex,51);
      cout<<"Case #"<<tcase<<": "<<out<<endl;
    }

    int main(){
        int T;
        s(T);
        for(int i=1;i<=T;i++){
            solve(i);
        }
    return 0;
    }