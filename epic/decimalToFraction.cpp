#include<iostream>
#include<math>

using namespace std;
string decimalToFraction(double input){

 long long number = input/1.0;
 input = input -  number;
 string res;


  return res;
}


int main()
{
 double n;
 cin>>n;
 cout<<" decimal converted to fraction string is << decimalToFraction(n) << endl;

return 0;
}
