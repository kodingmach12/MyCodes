#include<iostream>
#include<algorithm>
#include<cassert>
#define MAX 1000000
#define forall(i,a,b) for(i=a;i<=b;i++)
#define iforall(i,a,b) for(i=a;i>=b;i--)
#define COLUMN 4
#define ROW 4
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
bool novice_search(int m[][COLUMN],int r, int c, int x)
{
    if( x<m[0][0] || x>m[r-1][c-1] )
        return false;
    int i=r-1,j=0;
    while(i>=0 && j <c)
    {
     //   cout<<" "<<i<<" "<<j<<" "<<m[i][j]<<endl;
        if(m[i][j]==x)
            return true;
        if( x > m[i][j])
            j++;
        else if( x < m[i][j])
            i--;
    }
return false;
}

bool search_helper(int m[][COLUMN], int topx, int topy, int btmx, int btmy, int x)
{
    if( x < m[topx][topy] || x > m[btmx][btmy])
        return false;
    if(topx==topy && btmx==btmy)
    {
        if(m[topx][topy]==x)
            return true;
        else
            return false;
    }

    if(btmx==(topx+1) && btmy==(topy+1) )
    {
        if( x==m[topx][topy] || x==m[topx][btmy] || x==m[btmx][topy] || x==m[btmx][btmy])
            return true;
        else
            return false;
    }

    bool res=false;
    int midx = (topx+btmx)/2;
    int midy = (topy+btmy)/2;

    if( x == m[midx][midy]){
        cout<<" "<<midx<<" "<<midy<<endl;
        return true;
    }
    if( x > m[midx][midy])
    {
        return  search_helper(m,midx,midy,btmx,btmy,x);
    }
    if( x < m[midx][midy])
    {
        res=search_helper(m,topx,topy,midx,midy,x);
        if(!res)
            res=search_helper(m,topx,midy,midx,btmy,x);
        if(!res)
            res=search_helper(m,midx,topy,btmx,midy,x);
    }
return res;
}
bool grid_search(int m[][4], int row, int col, int x)
{
    int topx=0,topy=0,btmx=row-1,btmy=col-1;
    bool res = search_helper(m,topx,topy,btmx,btmy,x);
    return res;
}

int main()
{
    int m[][4]={
        {1,5,9,13},
        {2,6,10,14},
        {3,7,11,15},
        {4,8,12,16}};
    int k,i=1,r=4,c=4;
    printMatrix(m,r,c);
    cin>>k;
    forall(k,0,16){
    if(novice_search(m,r,c,k))
        cout<<" Found "<<endl;
    else
        cout<<" Not Found "<<endl;
    }
/*    if(grid_search(m,r,c,k))
        cout<<" Found "<<endl;
    else
        cout<<" Not Found "<<endl; */
//    cout<<endl<<" "<<i<<"  th element is "<<kth_matrix( m, r, c, k);
return 0;
}
// Quad - partition search
bool quadPart(int mat[][N_MAX], int M, int N, int target, int l, int u, int r, int d, int &targetRow, int &targetCol)
{
  if (l > r || u > d) return false;
  if (target < mat[u][l] || target > mat[d][r]) return false;
  int col = l + (r-l)>>1;
  int row = u + (d-u)>>1;
  if (mat[row][col] == target) {
    targetRow = row;
    targetCol = col;
    return true;
  }
  else if (l == r && u == d)
  {
    return false;
  }
  if (mat[row][col] > target)
  {
    return quadPart(mat, M, N, target, col+1, u, r, row, targetRow, targetCol) ||
           quadPart(mat, M, N, target, l, row+1, col, d, targetRow, targetCol) ||
           quadPart(mat, M, N, target, l, u, col, row, targetRow, targetCol);
  }
  else
  {
    return quadPart(mat, M, N, target, col+1, u, r, row, targetRow, targetCol) ||
           quadPart(mat, M, N, target, l, row+1, col, d, targetRow, targetCol) ||
           quadPart(mat, M, N, target, col+1, row+1, r, d, targetRow, targetCol);
  }
}

bool quadPart(int mat[][N_MAX], int N, int target, int &row, int &col) {
  return quadPart(mat, N, N, target, 0, 0, N-1, N-1, row, col);
}
