#line 5 "CasketOfStarEasy.cpp"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
class CasketOfStarEasy {
	public:
//vector< vector<int> > mem(50,vector<int>(50,-1));
int mem[50][50];
int rec(int a, int b,vector<int> &v)
{
        int& res = mem[a][b];
        if (res == -1) 
	{
            res = 0;
// Pick c - the element we will remove last: 
            for (int c=a+1; c<b; c++) {
// if we remove c last, we can find the score of the sub-vector a..c 
// and c..b to know the best strategy for the previous elements. 
                res = std::max(res, v[a]*v[b] + rec(a,c,v) + rec(c,b,v) ); 
            }
        }
        return res;
}
int maxEnergy(vector <int> v) 
{
        // int mem[50][50];
//         memset(mem,-1,sizeof(mem));
         return rec(0, v.size()-1,v);
}
};
int main()
{
CasketOfStarEasy A;
vector<int> v;
int n,elem;
cin>>n;
	while(n--)
	{
		cin>>elem;
		v.push_back(elem);
	}
int tot=A.maxEnergy(v);
cout<<endl<<tot<<endl;
return 0;
}


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
