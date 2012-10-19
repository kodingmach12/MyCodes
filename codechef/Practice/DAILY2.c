#include<stdio.h>
#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",&n)
#define forall(i,a,b) for(i=a;i<b;i++)
void solver()
{
int x,n,i=0,j=0,free=0,total=0,start,end,a,b;
scanf("%d",&x);
scanf("%d",&n);
char status[10][54];
int perm[6][6]={
{1,2,3,4,5,6},
{0,1,3,6,10,15},
{0,0,1,4,10,20},
{0,0,0,1,5,15},
{0,0,0,0,1,6},
{0,0,0,0,0,1}
};
forall(i,0,n)
	scanf("%s",status[i]);

//printf("%d\t%d\n",x,n);
//forall(i,0,n)
//	printf("%s\n",status[i]);

 for(i=0;i<n;i++)
 {
	start=0;
	end=53;	
	free=0;
//	total=0;
   for(j=0;j<9;j++)
   {	free=0;
	for(a=start;a<(start+4);a++)
	{  if(status[i][a]=='0')
		free++;
	}
 	for(b=end;b>(end-2);b--)
 	{  if(status[i][b]=='0')
		free++;
 	}
     start+=4;
     end-=2;
      if(free>=x)	
	total+=perm[x-1][free-1];
  //printf("%d\t%d\t%d\n",n,free,total);
   }
} 
 printf("%d\n",total);
 
}


int main()
{
int tcases=0;
scanf("%d",&tcases);
    while(tcases--)
	solver();
return 0;
}
