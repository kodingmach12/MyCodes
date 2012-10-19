#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void computeLPSArray(char *pat, int M, int *lps);

void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    while(i < N)
    {
      // mismatch after j matches
      if(pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if(j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
      if(pat[j] == txt[i])
      {
        j++;
        i++;
      }
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
    }
    free(lps); // to avoid memory leak
}

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
       if(pat[i] == pat[len])
       {
         len++;
         lps[i] = lps[i-1]+1;
         i++;
       }
       else // (pat[i] != pat[len])
       {
	   /*
	     lps[i]=0;
		 len=0;
		 if(pat[len]==pat[i])
		  lps[i]=1;
		  i++;*/
         if( len != 0 )
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
		 
       }
    }
	printf("\n");
for(i=0;i<M;i++)
	printf("  %d",*(lps+i));
	printf("\n");
	
	}

// Driver program to test above function
int main()
{
   char *txt = "AABAACAADAABAAABAA";
   char *pat = "BABCBABAB";
   KMPSearch(pat, txt);
   getchar();
   return 0;
}
