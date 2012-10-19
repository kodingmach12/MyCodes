#include<stdio.h>
// Returns the length of the longest increasing subsequence.
// Note that this is looking for the longest strictly increasing subsequence.
// This can be easily modified for other situations.
int lis( int* a, int N )
{
   int  *best,*prev, i, j, max = 0;
   best = (int*)malloc(sizeof(int)*N);
   prev = (int*)malloc(sizeof(int)*N);
   for ( i = 0; i < N; i++ )
	best[i] = 1, prev[i] = i;

   for ( i = 1; i < N; i++ )
      for ( j = 0; j < i; j++ )
         if ( a[j] < a[i] && best[i] < best[j] + 1 )
            best[i] = best[j] + 1, prev[i] = j;  // prev[] is for backtracking the subsequence
    printf("\n");
    for(i=0;i<N;i++)
        printf(" %d",best[i]);
    printf("\n");
    for(i=0;i<N;i++)
        printf(" %d",prev[i]);

    int maxpos=0;
   for ( i = 0; i < N; i++ )
      if ( max < best[i] ){
         max = best[i];
         maxpos = i;
        }
    printf("\n");
    printf(" %d ",a[maxpos]);
   while(maxpos)
   {
    printf(" %d",a[ prev[maxpos] ]);
    maxpos=prev[maxpos];
   }
   free( best );
   free( prev );
   return max;
}
int main()
{
  int b[] = { 1, 3, 2, 4, 3, 5, 4, 6 };
  int i;
  for(i=0;i<8;i++)
        printf(" %d",b[i]);

  // the longest increasing subsequence = 13456?
  // the length would be 5, as well lcs(b,8) will return.
  printf("\n%d\n", lis( b, 8 ) );
}
