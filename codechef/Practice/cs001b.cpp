#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
void solver()
{
  string s;
 long double a,b;
 long double res,sum;
 cin>>a>>b;
 res=pow(a,b);

cout.setf( ios_base::fixed, ios_base::floatfield );
    cout.precision( 0 );
    cout <<res << endl;
    while(res)
      {
	sum+=res%10.00;
	res/=10.00;
      }
    cout<<sum;
}

int main()
{
  solver();
return 0;
}

