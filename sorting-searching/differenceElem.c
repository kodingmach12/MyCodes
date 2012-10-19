#include<stdio.h>
int main()
{
    int arr[9]= {1, 2, 3, 4, 4, 5};
    int i = 0;
    int j = 1;
    int num = 2,cnt=0;
    while(j<6)
    {cnt++;
        int diff=   arr[j]-arr[i];
        if(diff == num)
        {
            printf("\ntwo numbers whose difference is equal"
                   " to %d are %d %d",num, arr[i],arr[j]);
            i++;
            j++;
        }
        else if(diff>num)
            i++;
        else if(diff<num)
            j++;
    }
    printf("\ncnt is %d",cnt);
}
