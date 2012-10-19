#include<stdio.h>
int main()
{
   int B[] = {3,1,4,3,1,3,20,4,4,1};
   int ones = 0 ;
   int twos = 0 ;
   int not_threes, x ;
   int i;
   for( i=0; i< 10; i++ )
   {
            x =  B[i];
            twos |= ones & x ;
            ones ^= x ;
            not_threes = ~(ones & twos) ;
            ones &= not_threes ;
            twos &= not_threes ;
   }

   printf("\n unique element = %d \n", ones );
   return 0;
}
