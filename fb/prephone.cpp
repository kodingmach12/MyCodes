    //Data Structure includes
    #include<vector>
    #include<stack>
    #include<set>
    #include<map>
    #include<queue>
    #include<deque>
    #include<string>
    #include<sstream>

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
    class balance{
    public:
      int wl,wr,wl_add,wr_add;
      vector<int> wl_balances,wr_balances;
      bool isBalanced;
    };

    vector<balance> in;

    int getBalanceWeight( int index ){
      int res =  in[index].wl + in[index].wr + 10;

      // add the weight of left balances
      for(int i=0;i<in[index].wl_balances.size() ; i++){
        res += getBalanceWeight(in[index].wl_balances[i]);
      }

      // add the weight of left balances
      for(int i=0;i<in[index].wr_balances.size() ; i++){
        res += getBalanceWeight(in[index].wr_balances[i]);
      }
      return res + in[index].wl_add + in[index].wr_add;
    }

    void printbalanceInfo(balance b){
      cout << " left weight is " << b.wl << endl;
      cout << " right weight is " << b.wr << endl;

      cout << " left dep balances size is " << b.wl_balances.size() << " : " ;
      for(int i=0;i<b.wl_balances.size();i++){
        cout << b.wl_balances[i] <<" ";
      }
      cout << endl;
      cout << " right dep balances size is " << b.wr_balances.size() << " : ";
      for(int i=0;i<b.wr_balances.size();i++){
        cout << b.wr_balances[i] <<" ";
      }
      cout << endl;

    }


    void solveChain(int index){
      if(in[index].isBalanced){
        return;
      }

      // first balance the left part
      for(int i=0;i<in[index].wl_balances.size(); i++){
        cout << index << " in1 " << endl;
        solveChain(in[index].wl_balances[i]);
      }

      // balance the right part
      for(int i=0;i<in[index].wr_balances.size(); i++){
        cout << index << " in2 " << endl;
        solveChain(in[index].wr_balances[i]);
      }

      int left_weight = in[index].wl;
      for(int i=0;i<in[index].wl_balances.size(); i++){
        cout << index << " in3 " << endl;
        left_weight += getBalanceWeight( in[index].wl_balances[i] );
      }

      int right_weight = in[index].wr;
      for(int i=0;i< in[index].wr_balances.size(); i++){
        cout << index << " in4 " << endl;
        right_weight += getBalanceWeight( in[index].wr_balances[i] );
      }
      cout << index << " " << left_weight << " " << right_weight << endl;
      if( left_weight > right_weight){
        in[index].wl_add = 0;
        in[index].wr_add = left_weight - right_weight;
      }
      else if (left_weight < right_weight){
        in[index].wr_add = 0;
        in[index].wl_add = right_weight - left_weight;
      }
      else{
        in[index].wl_add = in[index].wr_add = 0;
      }
      in[index].isBalanced = true;
    }

    vector<int> v;
    void tokenizeInput(string s){
      v.clear();
      istringstream iss(s);
      do
      {
          string sub;
          iss >> sub;
          // cout << iss << " " << sub << " " << endl;
          v.push_back(atoi(sub.c_str()));
      } while (iss);
      v.pop_back();
    }

    void solve(){
      int n = 1;
      string input;
      getline(cin,input);
      std::stringstream  linestream(input);
      linestream >> n;
      for(int i=0;i<n;i++){
        balance b;

        getline(cin,input);
        // cout << " input is " << input << endl;
        tokenizeInput(input);
        // for(int i=0;i<v.size();i++){ cout << " " << v[i];}
        // cout << endl;
        b.wl = v[0];
        for(int i=1;i<v.size(); i++){
          b.wl_balances.push_back(v[i]);
        }

        getline(cin,input);
        // cout << " input is " << input << endl;
        tokenizeInput(input);
        // for(int i=0;i<v.size();i++){ cout << " " << v[i];}
        // cout << endl;
        b.wr = v[0];
        for(int i=1;i<v.size(); i++){
          b.wr_balances.push_back(v[i]);
        }

        b.isBalanced = false;
        b.wl_add = b.wr_add = 0;
        // printbalanceInfo(b);
        in.push_back(b);
      }
      for(int i=0;i<n;i++){
        solveChain(i);
      }
      for(int i=0;i<n;i++){
        cout << i << " : " << in[i].wl_add << " " << in[i].wr_add << endl;
      }
    }

    int main(){
        solve();
    return 0;
    }
