#include<stdio.h>
#include<assert.h>
#include<limits.h>
// Time Complexity -> O(lg m)+ O(lg n)
int findKthsmallest(int A[],int m,int B[],int n,int k)
{
    assert(m >= 0); assert(n >= 0); assert(k > 0); assert(k <= m+n);
    int i = (int)((double)m / (m+n) * (k-1));
    int j = (k-1) - i;
    assert(i >= 0); assert(j >= 0); assert(i <= m); assert(j <= n);

    int Ai_1 = ((i==0)?INT_MIN : A[i-1]);
    int Bj_1 = ((j==0)?INT_MIN : B[j-1]);
    int Ai   = ((i==m)?INT_MAX : A[i]);
    int Bj   = ((j==n)?INT_MAX : B[j]);
    if (Bj_1 < Ai && Ai < Bj)
        return Ai;
    else if (Ai_1 < Bj && Bj < Ai)
        return Bj;

    if(Ai>Bj_1 && Ai<Bj)    return Ai;
    if(Bj>Ai_1 && Bj<Ai)    return Bj;

    if(Ai<Bj)   return findKthsmallest(A+i+1,m-i-1,B,n,k-i-1);
    if(Bj<Ai)   return findKthsmallest(A,m,B+j+1,n-j-1,k-j-1);
}
int main()
{
int a[]={2, 4, 6, 8, 10, 12, 14};
int b[]={1, 3, 4,  5, 7,  9, 21};
int k,m=sizeof(a)/sizeof(a[0]),n=sizeof(b)/sizeof(b[0]);
scanf("%d",&k);
    printf("\n %dth element is %d\n",k,findKthsmallest(a,m,b,n,k));
return 0;
}
