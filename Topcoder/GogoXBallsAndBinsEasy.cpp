// BEGIN CUT HERE

// END CUT HERE
#line 5 "GogoXBallsAndBinsEasy.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class GogoXBallsAndBinsEasy {
	public:
	int solve(vector <int> T) {
	 	  int len=T.size();
	  int i=0;
	  int max=0;
	  vector<int>::iterator itrb,itre;
	  
	  for(i=0 ; i<len/2 ; i++)
	   {
	     itrb=T.begin()+i;
	     itre=T.end()-1-i;
	     max+=*itre-*itrb;
	     //	     cout<<" max "<<max<<" el "<<*itre<<" begin "<<*itrb<<endl;
	    }


	  return max;
	}
};
/*
int main()
{
  GogoXBallsAndBinsEasy A;
vector<int> T;
 int len,el;
cin>>len;
 while(len--)
   {
     cin>>el;
     T.push_back(el);
}
len=(A.solve(T));
 cout<<len<<endl;
return 0;
}
*/
