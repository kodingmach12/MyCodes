#include<stdio.h>
#define bool int
#define true 1
#define false 0
bool isprime(int n)
{
    if(n<=1)  return false;
    if(n==2)    return true;
    if(n%2==0)  return false;
    int i;
    for(i=3; i*i <=n; i+=2)
        if(n%i==0)  return false;
return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(isprime(n))
        printf("Its a prime\n");
    else
        printf("Its a composite number\n");

return 0;
}
