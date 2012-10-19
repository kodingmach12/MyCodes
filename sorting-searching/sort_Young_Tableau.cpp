#include<iostream>
#include<algorithm>
#include<cassert>
#define MAX 1000000
#define forall(i,a,b) for(i=a;i<=b;i++)
#define iforall(i,a,b) for(i=a;i>=b;i--)
using namespace std;

/*
T(n) -> O( m*n log(m))
S(n) -> O(n+m)
1. Using a data structure (int value, int row, int col), place the
first column of the array into a minheap. Because the columns are
sorted, the data can simply be copied in order, with row and column
numbers appended; no heap ordering operations will be needed to
establish the heap condition.

2. Print the root node of the heap.

3. Replace the root node with the element of the array that is in the
next column of the same row. If all of the elements in that row have
been printed, instead move the last node in the heap into the root
position and decrease the heap size by 1.

4. Perform a downheap operation to restore the heap condition.

5. Go back to step 2 if the heap is not empty.

Comments:

1. You can interchange "row" and "column" in the above description if
you prefer.

2. If the array is of size m by n, then the work involved in this
algorithm is O(m n log m) if you use the algorithm as described above,
or O(m n log n) if you switch "row" and "column."

3. The heap will have m or n nodes, so you need 3*m or 3*n extra
memory. I suppose that we could write this as O(m + n).
*/
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
        if(m[i][j] < next_right && m[i][j] < next_down )
            break;
        else if( next_right > next_down ){
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
    cout<<endl<<" "<<k<<"  th element is "<<kth_matrix( m, r, c, k);

return 0;
}
