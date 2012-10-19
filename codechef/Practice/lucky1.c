#include<stdio.h>
int f4(int);
int f7(int);
void solver()
{
int n;
scanf("%d",&n);



}
int f4(int n)
{
int cnt=0;
	while(n)
	{
	if(n%10==4)	
		cnt++;
	n/=10;
	}
return cnt;
}
int f7(int n)
{
int cnt=0;
	while(n)
	{
	if(n%10==7)
		cnt++;
	n/=10;
	}
return cnt;
}
int main()
{
int tcases=0;
scanf("%d",&tcases);
    while(tcases--)
	solver();
return 0;
}
