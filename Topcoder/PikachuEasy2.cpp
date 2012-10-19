// BEGIN CUT HERE

// END CUT HERE
#line 5 "PikachuEasy.cpp"
#include <iostream>
#include <string>
#include <vector>
class PikachuEasy {
	public:
string check(string word) {
string s1="pi",s2="ka",s3="chu";
int i=0,flg=0;
while(word.at(i)!='\0')
{
if(word.at(i)=='p')
{  
	if(word.at(i+1)=='i')     i+=2;
	else  	{
	flg=1;
	break; 	} 
}
else if(word.at(i)=='k')
{  

if(word.at(i+1)=='a') 
  i+=2;
else {
flg=1;
break; }  
}
else if(word.at(i)=='c')
{
if(word.at(i+1)=='h'&& (word.at(i+2)=='u') )
  i+=3;
else {
flg=1;
break;
}
} 
}
if(flg)
  cout<<"NO";
else
 cout<<"YES";
}
};
