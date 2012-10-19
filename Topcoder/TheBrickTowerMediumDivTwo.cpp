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

 class TheBrickTowerMediumDivTwo {
	public:
	int mindiff;
	int vsize;
	char* res;
	vector<int>& height;
	void permute(char* str, int len, int level)
	{
		//if last character is reached, print the string
		if(len == 1){
//		    printf("%s\n", str-level);
			int dist = 0;
			for(int i=1;i<vsize;i++){
				dist+= max(height[str[i]-48], height[str[i-1]-48]);
				if(dist < mindiff){
					mindiff = dist;
					res = str;
				}
			}
		    return;
		}
		int i,j;
		char temp;
		for(i=0; i<len  ; i++)
		{
		                //    swap(&(str[0]), &(str[i]));
		        if(i)
		        {
		            temp=str[i];
		            for(j=i;j>=1;j--)
		                str[j]=str[j-1];
		            str[0]=temp;
		        }
		        permute(str+1, len-1, level+1);
		        if(i)
		        {
		            temp=str[0];
		            for(j=0;j<i;j++)
		                str[j]=str[j+1];
		            str[j]=temp;
		              // swap(&(str[0]), &(str[i]));
		        }
		}
	}

	vector <int> find(vector <int> heights) {
			int len = heights.size();
			mindiff = 1000000;
			vsize = len;
			char str[8]={"0123456"};
			str[len]='\0';
			permute(str,len,0);
			height = heights;
			vector<int> f;
			for(int i=0;i<len;i++)
				f.push_back(res[i]-48);
			return f;
	}
};
