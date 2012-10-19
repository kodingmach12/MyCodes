#include<queue>
#include<deque>
#define pair<int,int> PII

bool MinOfMax(int arr,int n,int k,int& res)
{
    if(n<1 || k<1 )
        return false;
    int min,max;
    min=
    deque<PII> Q;
    PII elem;
    for(int i=0;i<n;i++)
    {
        elem = make_pair(arr[i],i);
        while(!Q.empty() || Q.front().second < (i-k+1))
            Q.pop_front();
        while(!Q.empty() || arr[i] > Q.end())
            Q.pop_back();

        Q.push_back(elem);
        min= min(min,Q.front().first);
    }
    res=min;
return true;
}
