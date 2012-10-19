//Other Includes
#include<iostream>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define fill(a,v) 					memset(a, v, sizeof a)
typedef long  LL;
LL N,M,x,y,z,w,curind,curval,maX,miN,d;

void print(LL change[][2])
{
    cout<<endl;
    for( int i=0;i<2*M;i++)
    cout<<change[i][0]<<" "<<change[i][1]<<endl;
    cout<<endl;
}
void updateMinMax()
{
    if(curval < miN)
        miN = curval;
    else if(curval > maX)
        maX = curval;
}
int partition(LL arr[][2],int low,int high)
{
	LL pivot0,pivot1,temp0,temp1;
	int down=low,up=high;
	pivot0=arr[low][0];
	pivot1=arr[low][1];
	while(down<up)
	{
		while(arr[down][0]<=pivot0 && down<high)
			down++;
		while(arr[up][0]>pivot0)
			up--;
		if(down<up)
		{	temp0=arr[down][0];
		    temp1=arr[down][1];
			arr[down][0]=arr[up][0];
			arr[down][1]=arr[up][1];
			arr[up][0]=temp0;
			arr[up][1]=temp1;
		}
	}
	arr[low][0]=arr[up][0];
	arr[low][1]=arr[up][1];
	arr[up][0]=pivot0;
	arr[up][1]=pivot1;
return up;
}

void qsort(LL arr[][2],int low,int high)
{
	int pos;
	if(low>=high)
		return;
    pos=partition(arr,low,high);
		qsort(arr,low,pos-1);
		qsort(arr,pos+1,high);
}

void solve()
{
    cin>>N>>M;
    LL change[2*M][2];
    fill(change,0);
    //cout<<"its ok !!"<<endl;
    for(int i=0;i<M;i++)
    {
        scanf("%ld%ld%ld%ld",&w,&x,&y,&z);
        if(w==1){
            change[2*i][0]    = x-1;
            change[2*i][1]   -= z;
            change[2*i+1][0]  = y;
            change[2*i+1][1] += z;
        }
        else
        {
            change[2*i][0]    = x-1;
            change[2*i][1]   += z;
            change[2*i+1][0]  = y;
            change[2*i+1][1] -= z;
        }
    }
  qsort(change,0,2*M);

  for(int i=0;i<2*M-1;i++)
  {
    if(change[i][0] == change[i+1][0])
    {
        change[i+1][1] += change[i][1];
        change[i][0] = -1;
        change[i][1]=0;
    }
  }

  for(int i=2*M-2;i>=0;i--)
    change[i][1] += change[i+1][1];

     maX = change[2*M-1][0]+change[2*M-1][1];
     miN = maX;
     curind=N;
     curval=N;
     d=0;

    for( int i=2*M-1;i>=0;i--)
    {
        if(change[i][0]!= -1)
        {
            if(curind>change[i][0])
            {
                curval = curind+d;
                updateMinMax();
                curval=change[i][0]+1+d;
                updateMinMax();
                curind=change[i][0];
            }
            if(curind == change[i][0] ){
                curval=change[i][0]+change[i][1];
                updateMinMax();
                d=change[i][1];
            }
        }
    }
    if(curind>1)
    {
        curval = 1+d;
        updateMinMax();
    }
    LL range= maX-miN;
    printf("%ld",range);
}
int main()
{
    int tcases,i;
    cin>>tcases;
    for(i=1;i<=tcases;i++)
    {
        solve();
    }
return 0;
}
