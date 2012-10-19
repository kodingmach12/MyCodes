#line 5 "PikachuEasy.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class PikachuEasy {
	public:
string check(string word) {
string s1="pi",s2="ka",s3="chu",yes="YES",no="NO";
int i=0,flg=0,lim=word.size();
while( i<lim)
{
if(word.at(i)=='p' &&  i+1 < lim ) 
{  
	if(word.at(i+1)=='i')     i+=2;
	else  	{
	flg=1;
	break; 	} 
}
else if(word.at(i)=='k' && i+1 < lim  )
{  

if(word.at(i+1)=='a') 
  i+=2;
else {
flg=1;
break; }  
}
else if(word.at(i)=='c' && i+2 < lim)
{
if(word.at(i+1)=='h'&& (word.at(i+2)=='u') )
  i+=3;
else {
flg=1;
break;
}
}
else
{
flg=1;
break;
}
} 

if(flg)
	return no;
else
	return yes;
}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
