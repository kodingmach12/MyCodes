#include<stdio.h>
#define int long long int 
// Prototype of a utility function that returns minimum of two integers
int min(int a, int b);
 
// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int C[n+1][k+1];
    int i, j;
 
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
 
    return C[n][k];
}
 
// A utility function to return minimum of two integers
int min(int a, int b)
{
    return (a<b)? a: b;
}
 
/* Drier program to test above function*/
int main()
{
  int x = 5, y = 2,up,down1,down2;
    scanf("%lld%lld",&x,&y);
    if(x<0)
      x*=-1;
    if(y<0)
      y*=-1;

    if(x==0 || y==0)
      printf("1\n");
    else
      printf ("%lld\n",binomialCoeff(x+y,x) );
    return 0;
}
