#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using  namespace std;

void sort123_2(int a[],int n){
    int i=0,pos1=0,pos3=n-1;
    while(i<=pos3){
        if(1==a[i]){
            a[i]=a[pos1];
            a[pos1]=1;
            pos1++;
            i++;
        }
        if(3==a[i] && i< pos3){
            a[i]=a[pos3];
            a[pos3]=3;
            pos3--;
        }

    }
}

void sort123_3(int arr[],int n)
{
    int zeropos=0,twopos=n-1;
    int i=0;
    for(i=0;i<=twopos;i++){
        if(1==arr[i]){
            swap(arr[i],arr[zeropos]);
            zeropos++;
        }
        else if(3==arr[i]){
            swap(arr[i],arr[twopos]);
            twopos--;
            i--;
        }/*
        int j=0;
    while(j<9)
        cout<<arr[j++]<<" ";
    cout<<" "<<" zeropos = " << zeropos << " i =  " << i << " twopos = " << twopos <<endl;
    */
    }
}
int main()
{
    int a[]={1,1,2,1,3,2,1,2,3},n,i;
    int b[]={1,2,2,1,3,3,2,1,2,3,2,1},m;
    sort123_3(a,9);
    sort123_3(b,12);
    i=0;
    while(i<9)
        cout<<a[i++]<<" ";
    cout<<endl;
    i=0;
    while(i<12)
        cout<<b[i++]<<" ";
    cout<<endl;
return 0;
}
