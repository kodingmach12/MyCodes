#include<iostream>
#include<cstdio>
using namespace std;
int binary_search(int M[], int L, int X[], int i)
{
    if(L==0)    return -1;
    int low=0,high=L-1;
    int mid;
    int key = X[i];
    while(low <= high)
    {
        if(key < X[M[low]])
            return low-1;
        else if( key > X[M[high]])
            return high;
        else
        {
            mid = low + (high-low)/2;
            if( key < X[ M[mid] ] )
                high=mid;
            else
                low =mid;
        }
    }
    return -1;
}
int longest_subsequence(int X[], int N)
{
    if(N<1) return -1;
    int L=0,M[N],P[N];
    for(int i=0;i<N;i++)
    {
        int j=binary_search(M,L,X,i);
        if(i==0)
            L=1,M[i]=0,P[i]=-1;
        else
        {
            P[i] = (j==-1) ? -1 : M[j];
            if( j==L-1 || X[i]<X[M[j+1]] )
                M[j+1]=i;
            if( j+1 >= L )
                L++;
        }
        printf("\n i= %d j=%d L=%d ",i,j,L);
    }
    printf("\n X:");
    for(int i=0;i<8;i++)
        printf(" %d",X[i]);
    printf("\n M:");
    for(int i=0;i<8;i++)
        printf(" %d",M[i]);
    printf("\n P:");
    for(int i=0;i<8;i++)
        printf(" %d",P[i]);

    return L;
}
void get_Subsequence(int X[],int n,int M[],int P[],int L,int out[])
{   int index;
    for(int i=L-1; index=M[i]; i--)
    {
        out[i]=X[index];
        index = P[index];
        if(index==-1)
            break;
    }
}
int main()
{
  int X[] = { 1, 3, 2, 4, 3, 5, 4, 6 };

  // the longest increasing subsequence = 13456?
  // the length would be 5, as well lcs(b,8) will return.
  printf("\n%d\n", longest_subsequence( X, 8 ) );
}
