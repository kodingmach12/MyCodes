#include <stdio.h>
#include<math.h>
int getOddOccurrence(int ar[], int ar_size)
{
     int i,j,res;
     i = 0; j = ar_size-1; res = 0;
     while(i < ar_size/2)
     {
        res = res - ar[i++] + ar[j--];
	printf("\n%d",res);
	}
     res = res - ar[i];
     return abs(res);
}
 
int main()
{
     int ar[] = {2,2, 3, 3, 3, 5, 5, 5, 6, 6, 6, 7, 7, 7};
     printf("\n%d\n", getOddOccurrence(ar, 13));
     getchar();
}

