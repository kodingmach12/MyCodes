#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;
// When n is very big, O( m+n ) is greater than O(m*lg n)

void find_intersection(int a[], int m, int b[], int n)
{
    if(m==0 || n==0)    return;
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(a[i]==b[j]){
                cout<<" "<<a[i]<<" "<<b[j]<<endl;
                i++;
                j++;
        }
        else if(a[i]<b[j])
            i++;
        else
            j++;
    }
}
int main()
{   int m,n,i=0,j;
    int a[]={1,3,5,6,7,8,9,21};
    int b[]={2,4,5,8,15,19,21};
    m=sizeof(a)/sizeof(a[0]);
    n=sizeof(b)/sizeof(b[0]);
    i=0;
    while(i<m)
        cout<<a[i++]<<" ";
    cout<<endl;
    i=0;
    while(i<n)
        cout<<b[i++]<<" ";
    cout<<endl;
    find_intersection(a,m,b,n);
return 0;
}

