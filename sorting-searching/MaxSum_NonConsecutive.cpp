//to find maximum sum of elements which are non-contiguous in the array
//          S(i) = MAX {S(i-1), S(i-2) + T(i) }
//              S(-1) = 0;
//          if i=0, S(i) = T(0);
#include<iostream>
using namespace std;
int maxval(int a,int b)
{
    return ( (a>b)? a : b );
}
int maxSum_Non_Consecutive_Elements(int a[],int n)
{
    int sum2=0,sum1=a[0],sum=0;
    for(int i=1;i<n;i++)
    {
        sum = maxval(sum2+a[i],sum1);
        sum2 = sum1;
        sum1 = sum;
        //cout<< " " << sum;
    }
 return sum;
}
int maxSum_Non_Consecutive_Elements2(int a[],int size)
{
    if(size==0) return 0;
    if(size==1) return a[0];
    if(size==2) return maxval(a[0],a[1]);
    int i=0,j=0,sum[2]={0,a[0]},max=a[0],val;

    for(i=1;i<size;i++)
    {
        val= (sum[(i)%2]> (sum[(i-1)%2]+ a[i]) )? sum[(i)%2]  : sum[(i-1)%2]+ a[i] ;
//        cout<<" "<<sum[0]<<" "<<sum[1]<<"  "<<val<<endl;

        sum[(i-1)%2]=val;
    }
return sum[size%2];
}
int main()
{
    int a[]={6,24,12,8,11,98};
    //int a[]={3,2,7,10};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<maxSum_Non_Consecutive_Elements(a,size)<<endl;
return 0;
}

