#include<stdio.h>
int fact(int n)
{
if(n==0 || n==1)
	return 1;
return n*fact(n-1);
}
void solver()
{
int x,n,i=0,j=0,free=0,total=0,start,end,a,b;
scanf("%d",&x);
scanf("%d",&n);
char status[10][54];
for(i=0;i<n;i++)
	scanf("%s",status[i]);

for(i=0;i<n;i++)
{
	start=0;
	end=53;	
	free=0;
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
 	  total+=fact(free)/(fact(x) * fact(free-x) );
   }
} 
 printf("%d\n",total);
}
int main()
{
  solver();
return 0;
}
