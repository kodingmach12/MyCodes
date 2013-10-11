#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",&n)
#define forall(i,a,b) for(i=a;i<b;i++)
#define p(n) printf("%d",n)
#define pl(n) printf("%d\n",n)
#define ps(n) printf("%s",n)
#define psl(n) printf("%s\n",n)
#define w(a,b) while(a<b)

void solver()
{
 long long int m,n,i,a,t=0,prev = 1;
 scanf("%lld%lld",&n,&m);
for(i=0;i<m;i++){
  scanf("%lld",&a);
  if(a-prev < 0){
    t+= (n-prev+a);
  }else{
      t+= (a-prev);
  }
  // printf("%lld %lld %lld\n",prev,a,t);
  prev = a;
 }
 // printf("%lld\n",t);
}


int main()
{
	solver();
return 0;
}
