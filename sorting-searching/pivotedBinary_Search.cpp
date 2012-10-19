#include<iostream>
using  namespace std;
void rotateArr(int a[],int n,int  k)
{
    if(k==n)    return;


}
int pivotedBinarySearch(int a[],int lo,int high,int k)
{
    if(lo>high)
        return -1;
    int mid=lo+(high-lo)/2;
    if(a[mid]==k)
        return mid;

    if(a[lo] <= a[mid])  // sorted lower half
    {
        if(k>=a[lo] && k<a[mid])
            return pivotedBinarySearch(a,lo,mid-1,k);
        else
            return pivotedBinarySearch(a,mid+1,high,k);
    }
    else  // sorted upper half
    {
        if(k>a[mid] && k<=a[high])
            return pivotedBinarySearch(a,mid+1,high,k);
        else
            return pivotedBinarySearch(a,lo,mid-1,k);
    }
}
int main()
{
    int a[]={99,100,101,1,2,4,7,9,13,24,45,56,72,89,98},n,i,k;
    n=15;
    cin>>k;
    //rotateArr(a,15,i);
    i=pivotedBinarySearch(a,0,n-1,k);
    if(i!=-1)
        cout<<"Found at "<<i<<endl;
    else
        cout<<"Not Found "<<endl;
    i=0;
    while(i<n)
        cout<<a[i++]<<" ";
    cout<<endl;
return 0;
}

