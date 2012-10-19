#include<stdio.h>
int main()
{
    int y=10;
    int z= y++ + y++;
    if( y++>9 && y++!=10 && y++>10)
        printf("% d\n",y);
    long long   curmean=0,sum=0,elem,res=1000000001;
    int N,i;
    int tcases=0;
    scanf("%d",&tcases);
    while(tcases--){
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%lld",&elem);
            sum+=elem;
            curmean =  sum/(i+1);
            res = (res < curmean) ? res : curmean;
            //printf("res:%d curmean:%d elem:%d\n",res,curmean,elem);
        }
        printf("%lld\n",res);
    }
}
