#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))
// by pre-sorting the data and using constraint checks, pruning can be done in the tree.
//using namespace std;
static int total_nodes;
// prints subset found
void printSubset(int A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%*d", 5, A[i]);
    }

    printf("\n");
}

// qsort compare function
int comparator(const void *pLhs, const void *pRhs)
{
    int *lhs = (int *)pLhs;
    int *rhs = (int *)pRhs;

    return *lhs > *rhs;
}

// inputs
// s            - set vector
// t            - tuplet vector
// s_size       - set size
// t_size       - tuplet size so far
// sum          - sum so far
// cur          - nodes count
// target_sum   - sum to be found
void subset_sum(int s[], int t[],
                int s_size, int t_size,
                int sum, int cur,
                int const target_sum)
{
    total_nodes++;
    if( target_sum == sum )
    {
        // We found sum
        printSubset(t, t_size);

        // constraint check
        if( cur + 1 < s_size && sum - s[cur] + s[cur+1] <= target_sum )
        {
            // Exclude previous added item and consider next candidate
            subset_sum(s, t, s_size, t_size-1, sum - s[cur], cur + 1, target_sum);
        }
        return;
    }
    else
    {
        // constraint check
        if( cur < s_size && sum + s[cur] <= target_sum )
        {
            // generate nodes along the breadth
            for( int i = cur; i < s_size; i++ )
            {
                t[t_size] = s[i];

                if( sum + s[i] <= target_sum )
                {
                    // consider next level node (along depth)
                    subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
                }
            }
        }
    }
}

// Wrapper that prints subsets that sum to target_sum
void generateSubsets(int s[], int size, int target_sum)
{
    if(size<1)  return;

    int total = s[0],min=s[0];
    // sort the set
    for( int i = 1; i < size; i++ )
    {
        min = (s[i] < min) ? s[i] : min ;
        printf(" %d ",s[i]);
        total += s[i];
    }

    printf("Array sum is %d \n",total);

    if( min <= target_sum &&  target_sum <= total )
    {
        qsort(s, size, sizeof(int), &comparator);
        int *subset = (int *)malloc(size * sizeof(int));

        subset_sum(s, subset, size, 0, 0, 0, target_sum);

        free(subset);
    }
}

int main()
{
    int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int target = 53;

    int size = ARRAYSIZE(weights);

    generateSubsets(weights, size, target);

    printf("Nodes generated %d\n", total_nodes);

    return 0;
}
