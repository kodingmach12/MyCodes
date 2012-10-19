#include<stdio.h>
#include<math.h>
#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",n)
void solver()
{
  double res;
  int a,b;
  scanf("%d%d",&a,&b);
  res=pow(a,b);
printf("%Lf",res);
}


int main()
{
int tcases=0;
scanf("%d",&tcases);
    while(tcases--)
	solver();
return 0;
}
