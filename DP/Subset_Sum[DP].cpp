#include<iostream>
using namespace std;
int cnt=0;
int subsetSum(int arr[],int len,int value,int  i )
{   cnt++;
    int tmp=0;
    if( i >=len) return 0;
    if( value== arr[i] )
    {
        cout<<" "<<arr[i];
        return 1;
    }
    if(value < arr[i])
      return  subsetSum(arr, len, value, i+1);

    if(value > arr[i]){
        tmp=subsetSum(arr,len,value-arr[i], i );
        if(tmp)
            cout<<" "<<arr[i];
        else
           tmp=subsetSum(arr,len,value, i +1);
    }
return tmp;
}
int main()
{
    int coins[]={10,8,5,4,2,1},sum,len,start;
    cin>>sum;
    len=6;
    start=0;
    if(subsetSum(coins,len,sum,start))
        cout<<endl<<"Sum Found"<<endl;
    else
        cout<<"Not Found"<<endl;
    cout<<"Total recursive calls = "<<cnt<<endl;
return 0;
}
