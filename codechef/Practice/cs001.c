#include<stdio.h>
#include<math.h>
#include<limits.h>
//#define int long long int
#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",&n)
void solver()
{
  int h,m,n,sum,rows,cols,i,j,el;
  scanf("%d%d%d",&h,&m,&n);
  rows=h;
  cols=(h*h)-((h-1)*(h-1)); 
  int arr[rows][cols],arr2[rows][cols];
  for(i=0;i<rows;i++)
    {
      for(j=0;j<cols;j++)
	{
	  if( j>=(cols/2-i) && j<=(cols/2+i) )
	    { 
   	    scanf("%d",&el);
	      arr[i][j]=el;
	    }
	  else
	    arr[i][j]=0;
	}
    }
  for(i=0;i<rows;i++)
      for(j=0;j<cols;j++)
	arr2[i][j]=0;

  int lb=m,rb=n,k=0;
  arr2[0][cols/2]=arr[0][cols/2];
  for(i=0;i<rows-1;i++)
    {
      lb=m;
      rb=n;
      for(j=(cols/2-lb);j<=(cols/2+rb);j++)
	{
	  if(arr[i][j]==0)
	    ;
	  else
	    {
	      lb=lb<(i+1)?lb:i+1;
	      rb=rb<(i+1)?rb:i+1;

	    for(k=j-lb;k<=j+rb;k++)
	      { int sum=arr2[i][j]+arr[i+1][k];
		if(arr2[i+1][k]==0)
		  arr2[i+1][k]=sum;
		else if(sum<arr2[i+1][k])
		  arr2[i+1][k]=sum;
	      }
	    }
	}
    }


  int min=INT_MAX;  
    for(i=0;i<cols;i++)
      {
	if(arr[rows-1][i]==0)
	  ;
	else if(arr2[rows-1][i]<min && arr2[rows-1][i]!=0 )
	  min=arr2[rows-1][i];
      }
    printf("%d\n",min);
}
int main()
{
  int tcases;
  scanf("%d",&tcases);
  while(tcases--)
	solver();
return 0;
}
