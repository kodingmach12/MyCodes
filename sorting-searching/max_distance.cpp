#include<iostream>
#include<algorithm>
using namespace std;
#define forall(i,a,b) for(i=a;i<b;i++)
#define iforall(i,a,b) for(i=a;i>=b;i--)
int maxdistance( int a[], int n, int& start, int &end)
{
    if(n<=1)    return 0;
    int Lmin[n],Rmax[n],i,j,maxdist=0,min,max;
    min = 0;
    Lmin[0] = min;
    forall(i,1,n)
    {
        if(a[i] < a[min] )
            min=i;
        Lmin[i]=min;
    }
    max = n-1;
    Rmax[n-1] = max;
    iforall(j,n-2,0)
    {
        if(a[j]>a[max])
            max=j;
        Rmax[j]=max;
    }

    cout<<" Lmin : "<<endl;
    forall(i,0,n)
        cout<<" "<<a[ Lmin[i] ];
    cout<<endl;

    cout<<" Rmax : "<<endl;
    forall(i,0,n)
        cout<<" "<<a[ Rmax[i] ] ;
    cout<<endl;

    i=0;
    j=0;

    while( i<n && j<n )
    {
        if( a[ Lmin[i] ] < a[ Rmax[j] ])
        {
            maxdist = Rmax[j] - Lmin[i] +1;
            start = Lmin[i];
            end = Rmax[j];
            j++;
        }
        else
            i++;
    }
if(start == end )
    return 0;
return 1;
}
int main()
{
    int a[20];
    int i=0,j=0,len=20;
    for(i=0;i<len;i++){
        a[i]=rand()%100;
        cout<<" "<<a[i];
    }
    cout<<endl;
    int s=0,e=0;
    int retval = maxdistance(a, len, s, e);
    if(retval)
    {
        cout<<a[s]<<" "<<a[e]<<" distance is "<<(e-s+1)<<endl;
    }
    else
     cout<<" No such pair found "<<endl;

return 0;
}
