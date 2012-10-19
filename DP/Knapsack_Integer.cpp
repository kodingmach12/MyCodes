#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;
int knapsack(int weight[], int cost[], int items, int capacity)
{
    int v[items+1][capacity+1],i=0,j=0;
    // initialise all values to 0
    for(i=0;i<=items;i++)
        for(j=0;j<=capacity;j++)
            v[i][j]=0;

    // memoization starts here
    for(i=1;i<=items;i++)
    {
        for(j=1;j<=capacity;j++)
        {
            if(  j < weight[i-1] )  // current capacity less than weight of current item, so can't be packed in it
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max( v[i-1][j], cost[i-1] + v[i-1][ j-weight[i-1] ] );
        }
    }
    for(i=0;i<=items;i++){
        for(j=0;j<=capacity;j++)
            cout<<" "<<v[i][j];
        cout<<endl;
    }

    // printing all the items used in the knapsack :-


return v[items][capacity];
}
int main()
{
    int weight[]={5,4,6,3},cost[]={10,40,30,50},items,capacity;
    cin>>items;
    cin>>capacity;
    //items=3;
    //capacity=10;
    cout<<" The maximum value filled can be "<<knapsack(weight,cost,items,capacity);
return 0;
}
