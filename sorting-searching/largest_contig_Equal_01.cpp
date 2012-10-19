#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int ** alloc2d(int row,int col)
{
int i=0;
int **ptr=(int**)malloc(row * sizeof(int*));
for(i=0;i<row;i++)
	ptr[i]=(int*)malloc(col * sizeof(int));
return ptr;
}
int largest_contiguous_equal_zero_one( int arr[], int n ,int *p, int *q)
{
    //int **v=alloc2d(n+1,2);
    //memset(v,-1,sizeof(int));
    int v[n+1][2];
    int i,sum=0,maxlen=0;

    for(i=0;i<=n;i++)
        v[i][0]=v[i][1]=-1;
    for(i=0;i<=n;i++)
        cout<<" "<<v[i][0]<<" "<<v[i][1]<<endl;
    for(i=0;i<n;i++)
    {
        sum+=( (arr[i]) ? 1 : -1);
        if( sum >= -n/2 && sum <= n/2)  // becoz sum outside this range won't be repeated
        {
            if( v[sum+n/2][0] == -1 )
                    v[sum+n/2][0]=i;
            else
                    v[sum+n/2][1]=i;
        }
    }
    for(i=0;i<n;i++)
    {
        if(v[i][0]!= -1 && v[i][1]!=-1 )
        {
            if(maxlen <(v[i][1] - v[i][0]) )
            {
                maxlen=v[i][1] - v[i][0];
                *p=v[i][0];
                *q=v[i][1];
            }
        }
    }
return maxlen;
}
int main()
{
    int a[]={1,1,0,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,1,1,1,1,1};
    int n=sizeof(a)/sizeof(int);
    int p=0,q=0,i;
    int len=largest_contiguous_equal_zero_one(a,n,&p,&q);
    cout<<" length is "<<len;
    for(i=p;i<=q;i++)
            cout<<" "<<a[i];
    cout<<endl;
return 0;
}
