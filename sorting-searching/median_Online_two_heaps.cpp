#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
#define forall(i,a,b)   for(i=a;i<b;i++)
using namespace std;
void display(vector<int> &v)
{
    vector<int> :: iterator it;
    for(it=v.begin(); it!=v.end(); it++)
        cout<<" "<<*it;
    cout<<endl;
}
void online_median()
{
    int total=0;
    cin>>total;
    vector<int> max,min;
    int maxcnt=0,mincnt=0,i,temp,elem,median;

    while(total)
    { total--;
      cin>>elem;
      max.push_back(elem);
      maxcnt++;

      if(maxcnt==mincnt+2)
      {
            pop_heap( max.begin(), max.end() );
            temp=max.back();
            max.pop_back();
            maxcnt--;

            min.push_back(temp);
            mincnt++;
            push_heap(min.begin(),min.end());

      }

      if(mincnt==0)                  median=max.front();
      else if(maxcnt==mincnt)        median=(max.front()+min.front())/2;
      else if(maxcnt==mincnt+1)      median=max.front();
      else
      {
        cout<<" Bug !!! Fix it please"<<endl;
      }
      cout<<maxcnt<<" ";
      display(max);
      cout<<mincnt<<" ";
      display(min);
      cout<<" Median : "<<median<<endl;
    }
}


int main()
{
    online_median();

return 0;
}
