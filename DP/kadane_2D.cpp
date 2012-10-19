#include<iostream>
#include<cstring>
using namespace std;
#define row 5
#define col 5
void kadane(int input[], int n, int &x1, int &x2, int &max)
{
    int cur, i;
    max = 0;
    cur = 0;
    x1 = x2 = 0;
    int lx1, lx2;
    lx1 = 0;
    for(int i = 0; i<n; i++)
    {
        cur = cur+input[i];
        if(cur > max)
        {
            max = cur;
            x2 = i;
            x1 = lx1;
        }
        if (cur < 0)
        {
            cur = 0;
            lx1 = i + 1;
        }
    }
}

int main()
{
    int tmp[col]={0},x1, x2;
    int cur, max_sum, fx1, fx2, fy1, fy2;
    int i,j,k,p;
    int input[row][col]={{  5, -4,  4,  -7, -9},
                         {  3, -6,  6,  -8,  8},
                         { -8, -7,-12,  -4, -5},
                         {-16, -1,  2, -12, -3},
                         { -5,  7,  6,  -8,  1}
                        };
    fx1 = fx2 = fy1 = fy2 = max_sum = cur = -1;
    for (i=0; i< row; i++){
        //for(k=0; k<col; k++)
            //tmp[k] = 0;
        memset(tmp,0,sizeof(int)*col);
        for (j=i; j<row; j++){
            for(k=0; k<col; k++)
                tmp[k] += input[j][k];

            /*for(p=0;p<col;p++)
                cout<<" "<<tmp[p];
            cout<<endl;*/

            kadane(tmp, col, x1, x2, cur);
            if (cur > max_sum){
                fy1 = x1;
                fy2 = x2;
                fx1 = i;
                fx2 = j;
                max_sum = cur;
            }
        }
    }
    cout << "max Sum = " << max_sum << " from (" << fx1 << "," << fy1 << ") to ("
        << fx2 << "," << fy2 << ")" << endl;
return 0;
}
