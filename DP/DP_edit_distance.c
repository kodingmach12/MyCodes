/* Dynamic Programming implementation of edit distance */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
/* Change these strings to test the program */
#define STRING_1 "SUNDAY"
#define STRING_2 "SATURDAY"
 
#define SENTINEL (-1)
#define EDIT_COST (1)
 
/* Helper to display table */
void display(int *base, int row, int col)
{
    int r, c;
 
    for(r = 0; r < row; r++)
    {
        for(c = 0; c < col; c++)
        {
            printf("\t%4d", *(base + r * col));
        }
 
        printf("\n\n");
    }
}
 
/* Returns minimum among a, b, c */
int minimum(int a, int b, int c)
{
    int min = c;
 
    /* Comparisons propotional to height
       of decision tree, here we need minimum 2 comparisons.
    */
    if( a < b )
    {
        if( a < c )
        {
            min = a;
        }
    }
    else
    {
        if( b < c )
        {
            min = b;
        }
    }
 
    return min;
}
 
/* Strings of size m and n are passed.
   Construct the table for X[0...m, m+1], Y[0...n, n+1]. */
int edit_distance( char *X, char *Y )
{
    /* Cost of alignment */
    int cost = 0;
    /* Cell data */
    int currentCell;
    int leftCell, topCell, cornerCell;
 
    /* We need an (m+1) x (n+1) matrix */
    int m = strlen(X) + 1; /* m is one more than X string length */
    int n = strlen(Y) + 1; /* n is one more than Y string length */
 
    /* table[m][n] */
    int *table = (int *)malloc( (m) * (n) * sizeof(int) );
 
    /* Indices */
    int i, j;
 
    /* Initialize the table (for visualisation) */
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            *(table + i * n + j) = SENTINEL;
        }
    }
 
    /* Set up base cases */
 
    /* table[0][0] = 0 */
    *table = 0;
    for (i = 1; i < m; i++)
    {
        /* table[i][0] = i */
        *(table + i * n) = i;
    }
    for (j = 1; j < n; j++)
    {
        /* table[0][j] = j */
        *(table + j) = j;
    }
 
    /* Algorithm visualisation stub */
    printf("After Base Cases\n");
    display(table, m, n);
 
    /* Build the table in bottom-up fashion */
    for (i = 1; i < m; i++)
    {
        for (j = 1; j < n; j++)
        {
            /* table[i-1][j] */
            leftCell = *( table + (i-1)*n + j );
            leftCell += EDIT_COST;
 
            /* table[i][j-1] */
            topCell = *( table + i*n + (j-1) );
            topCell += EDIT_COST;
 
            /* table[i-1][j-1] */
            cornerCell = *( table + (i-1)*n + (j-1) );
            /* edit[(i-1), (j-1)] + 0 if X[i] == Y[j], 1 otherwise */
            cornerCell += (X[i-1] != Y[j-1]);
 
            /* Minimum cost of current cell */
            currentCell = minimum(leftCell, topCell, cornerCell);
 
            /* Fill in the next cell table[i][j] */
            *( table + (i)*n + (j) ) = currentCell;
        }
 
        /* Algorithm visualisation stub */
        printf("Table After Completion of Row\n");
        display(table, m, n);
        printf("\n\n");
    }
 
    /* Cost is in the last cell of table */
    cost = *(table + (m * n) - 1);
 
    free(table);
 
    return cost;
}
 
/* Reursive implementation */
int edit_distance_recursive( char *X, char *Y, int m, int n )
{
    /* Base cases */
    if(m == 0 && n == 0)
    {
        return 0;
    }
 
    if(m == 0)
    {
        return n;
    }
 
    if( n == 0 )
    {
        return m;
    }
 
    /* Recurse */
    int left   = edit_distance_recursive(X, Y, m-1, n) + 1;
    int right  = edit_distance_recursive(X, Y, m, n-1) + 1;
    int corner = edit_distance_recursive(X, Y, m-1, n-1) + (X[m-1] != Y[n-1]);
 
    return minimum(left, right, corner);
}
 
/* Driver stub to test edit_distance */
int main()
{
    char X[] = STRING_1;
    char Y[] = STRING_2;
 
    printf("Minimum edits required to convert %s into %s is %d\n",
                   X, Y, edit_distance( X, Y ) );
    printf("Minimum edits required to convert %s into %s is %d by recursion\n",
                   X, Y, edit_distance_recursive( X, Y, strlen(X), strlen(Y) ) );
 
    return 0;
}
