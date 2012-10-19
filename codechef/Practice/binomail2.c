#include<stdio.h>
// Prototype of a utility function that returns minimum of two long long integers
long long int min(long long int a, long long int b);
 
// Returns value of Binomial Coefficient C(n, k)
long long int binomialCoeff(long long int n, long long int k)
{
    long long int C[n+1][k+1];
    long long int i, j;
 
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
 
// A utility function to return minimum of two long long integers
long long int min(long long int a, long long int b)
{
    return (a<b)? a: b;
}
 
/* Drier program to test above function*/
long long int main()
{
    long long int n = 5, k = 2;
    scanf("%lld",&n);
    scanf("%lld",&k);
    printf ("Value of C(%lld, %lld) is %lld ", n, k, binomialCoeff(n, k) );
    return 0;
}
