//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
#define gcd                   __gcd

typedef long long LL;

/*Main code begins now */

LL N,Tot;
bool isPrimeN = false;
int divisors[100000001];
LL  returndivisors(LL num)
{
    if(num <= 2)
        return num;
    LL low=1,up=num;
    LL lim = sqrt(num);
    LL count = 0;
    for( ; low<=lim;  low++)
        if( (num%low)==0)
        {
            count+=2;
            up=num/low;
            if(low==up)
                count--;
        }
    return count;
}

LL getDivisors(LL num)
{
    if( num == N )
        return Tot;
    if( num <= 100000000)
    {
        if( divisors[num] == 0 ){
            divisors[num]=returndivisors(num);
        }
        return divisors[num];
    }
    return returndivisors(num);
}

void solve()
{
    LL T,K,temp,res;
    scanf("%lld%lld",&T,&K);
    if(T==1)
    {
        temp = gcd(N,K);
        printf("%lld\n",getDivisors(temp));
    }
    else if(T==2)
    {
        if( 0==N%K)
        {
            temp = (N/K);
            printf("%lld\n",getDivisors(temp));
        }
        else
            printf("0\n");
    }
    else if(T==3)
    {
        temp = 0;
        if(0==N%K)
            temp = N/K;
        res=Tot-getDivisors(temp);
        printf("%lld\n",res);
    }
}
int main()
{
    LL  Q;
    scanf("%lld",&N);
    scanf("%lld",&Q);
    Tot = returndivisors(N);
//    if(Tot==2)
  //      isPrimeN = true;
    while(Q--)
        solve();
    return 0;
}
