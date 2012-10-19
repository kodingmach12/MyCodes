#include<iostream>
#include<algorithm>
#include<cassert>
#define MAX 1000000
#define forall(i,a,b) for(i=a;i<=b;i++)
#define iforall(i,a,b) for(i=a;i>=b;i--)
using namespace std;
void printMatrix(int m[][4],int r, int c)
{
    int i=0,j=0;
    forall(i,0,r-1){
        forall(j,0,c-1)
            cout<<" "<<m[i][j]<<" ";
        cout<<endl;
    }
}
void youngify(int m[][4], int row, int col)
{
    int i=0,j=0;
    while(1)
    {
        int next_right = ( j+1 <= col ) ? m[i][j+1] : MAX ;
        int next_down  = ( i+1 <= row ) ? m[i+1][j] : MAX ;
        if(m[i][j] <= next_right && m[i][j] <= next_down )
            break;
        else if( next_right > next_down )
        {
            swap( m[i][j] , m[i+1][j] );
            i++;
        }
        else
        {
            swap( m[i][j] , m[i][j+1] );
            j++;
        }
    }
}
int kth_matrix(int m[][4], int r, int c,int k)
{
    assert(k>0);
    assert(k<= r*c);
    int i,j,lrow,lcol,tmp;
    lrow=r-1;
    lcol=c-1;
    while(k>1)
    {   k--;
        cout<<" "<<m[0][0];
        m[0][0]=m[lrow][lcol];
        m[lrow][lcol] = MAX;
        if(lcol){
            lcol--;
        }
        else
        {
            lcol=c-1;
            lrow--;
        }
        youngify( m, r-1, c-1);
        /*cout<<"Matrix Starts Here"<<endl;
                printMatrix(m,4,4);
        cout<<"Matrix Ends Here"<<endl;*/
    }
return m[0][0];
}
int main()
{
    int m[][4]={
        {1,5,9,13},
        {2,6,10,14},
        {3,7,11,15},
        {4,8,12,16}};
    int k,i=1,r=4,c=4;
    cin>>k;
    //for(int k=1;k<16;k++)
        cout<<endl<<" "<<k<<"  th element is "<<kth_matrix( m, r, c, k);

return 0;
}
