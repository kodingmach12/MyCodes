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

#define FOR(i,a,b)		for(int i=a;i<b;i++)
#define REP(i,n)		FOR(i,0,n)
#define pb			push_back
#define mp			make_pair
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define ss(n) 			scanf("%s",n)
#define fill(a,v) 			memset(a, v, sizeof a)
#define sz			size()
#define INF			(int)1e9
#define EPS			1e-9
#define bitcount			__builtin_popcount
#define all(x)			x.begin(), x.end()
#define gcd			__gcd
#define maX(a,b)		(a>b?a:b)
#define miN(a,b)		(a<b?a:b)
#define DREP(a)		sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)		lower_bound(all(arr),ind)-arr.begin())
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef vector<long long > VLL;
typedef pair<int, int > PII;using namespace std;
class EllysJuice {
	public:
	vector <string> getWinners(vector <string> p)
	{
	    vector<string> winners;
	    vector< pair<string,int> > cnt;
	    pair<string,int> elem;

        int amt[]={8,8,4,4,2,2,1,1};
        int len=p.size();

        vector<string> :: iterator it;
        vector< pair<string,int> > :: iterator pit;

        bool added=false;

        for(it=p.begin(); it!=p.end(); it++)
        {
            added=false;
            for(pit=cnt.begin(); pit!=cnt.end(); pit++)
            {
                if((*pit).first == *it)
                {
                    ((*pit).second)++;
                    added=true;
                }
            }
            if(!added){
                elem.first=(*it);
                elem.second=1;
                cnt.push_back(elem);
            }

        }
        sort(cnt.begin(), cnt.end());
        int uniq=cnt.size();
        if(uniq==1 || uniq==len)
        {
            for(pit=cnt.begin(); pit!=cnt.end(); pit++)
            {
                winners.push_back( (*pit).first);
            }
        }




    // sort the string
	}
	int partition(char *arr,int low,int high)
{
	int pivot,temp,down=low,up=high;
	pivot=arr[low];
	while(down<up)
	{
		while(arr[down]<=pivot && down<high)
			down++;
		while(arr[up]>pivot)
			up--;
		if(down<up)
		{	temp=arr[down];
			arr[down]=arr[up];
			arr[up]=temp;
		}
	}
	arr[low]=arr[up];
	arr[up]=pivot;
	return up;
}

void qsort(char *arr,int low,int high)
{
	int pos;
	if(low>=high)
		return;
	pos=partition(arr,low,high);
		qsort(arr,low,pos-1);
		qsort(arr,pos+1,high);
}

};
