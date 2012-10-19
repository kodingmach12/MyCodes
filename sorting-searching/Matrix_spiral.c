#include<stdio.h>
#include<conio.h>
#define p(n) printf(" %d ",n)
void printSpiral(int m[][6],int r,int c)
{
    int i,j,k;
    for(i=0;i<=r/2;i++)
    {
        //printf("\ti = %d j = %d \n",i,j);
        for(j=i;j<c-i-1;j++)
            p(m[i][j]);
        //printf("\ti = %d j = %d \n",i,j);
        for(k=i;k<r-i-1;k++)
            p(m[k][j]);
        //printf("\ti = %d j = %d k =%d\n",i,j,k);
        for(j=c-i-1;j>i;j--)
            p(m[k][j]);
        //printf("\ti = %d j = %d k =%d\n",i,j,k);
        for(k=r-i-1;k>i;k--)
            p(m[k][j]);
        //printf("\ti = %d j = %d k =%d\n",i,j,k);
    }
    //printf("i = %d j = %d \n",i,j);
}
int main()
{
int ar[][6]={{ 1, 2, 3, 4, 14, 1},
             { 5, 6, 7, 8, 18, 1},
             { 9,10,11,12, 22, 1},
             {13,14,15,16, 26, 1},
             { 9,10,11,12, 22, 1},
             {14,10, 9, 7, 17, 1}};
    int r=6,c=6;
    printSpiral(ar,r,c);
return 0;
}
