#include<stdio.h>
int returnk(int arr1[],int arr2[],int start1,int size1,int start2,int size2,int k)
{
    int pos=0;
    if(  k > (size1+size2) )
    {
        printf("Not found");
        return -1;

    }

    if(arr1[size1-1] < arr2[0])
    {
        if(k>=size1)
            return arr2[k-size1-1];
        else
            return arr1[k];
    }
    if(arr2[size-1] < arr1[0])
    {
        if(k>=size2)
            return arr1[k-size-1];
        else
            return arr2[k];
    }
    if(arr1[size1/2] < arr2[size2/2] )
        pos=size/2+size2/2+1;


}

int main()
{
int arr1[]={};
int arr2[]={};
int k=0;
scanf("%d",&k);
printf("\nThe element is %d",returnk( ,,,,,,  ));
return 0;
}


//b-2 4 6 8 10 12
//a-1 3 4  5 7  9 11
