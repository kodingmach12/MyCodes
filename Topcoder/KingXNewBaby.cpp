#line 83 "KingXNewBaby.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class KingXNewBaby {
	public:
	string isValid(string s) {
    int res=1,i,con=0,a=0,e=0,i=0,o=0,u=0;
    if(s.size()!=8) res=0;
    for(i=0;i<8;i++)
    {
    if(s.at(i)=='a')
        a++;
    else if(s.at(i)=='e')
        e++;
    else if(s.at(i)=='i')
        i++;
    else if(s.at(i)=='o')
        o++;
    else if(s.at(i)=='u')
        u++;
    else
        con++;
    }
    if(con!=6)  res=0;
    if(a!=2 && e!=2 && i!=2 && o!=2 && u!=2  )
        res=0;
    if(res)
        return "YES";
    else
        return "NO";
	    	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
