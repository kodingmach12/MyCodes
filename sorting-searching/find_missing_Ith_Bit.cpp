#include<iostream>
#include<algorithm>
using namespace std;
#define MAXBIT (8 * sizeof(int))

bool get_bit(int n,int j)
{
    if(n==0)    return false;
    if(j)   n=n>>j;
    return n%2;
}

int  partition(int arr[], int start, int end,  int bit_num)  //partition function  based on jth bit set
{
    int left=start;
    int i=start;
    while(get_bit(arr[i],bit_num)==0)
    {
        left++;
        i++;
    }
    for( ; i<end ; i++)
    {
        if( get_bit(arr[i],bit_num) == 0  )
        {
            swap(arr[i],arr[left]);
            left++;
        }
    }
return left;
}

int find_missing(int arr[],int n)
{
    int cur_bit=0;
    int start=0,end=n,pivot=0;

    while(cur_bit<MAXBIT)
    {
        pivot= partition(arr, start, end, cur_bit);


    }


}

