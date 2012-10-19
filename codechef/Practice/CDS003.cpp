#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;
void solver()
{
string s;
cin>>s;
 string out,cur;
 int len=s.size(),num,i=0; 
 char small[27]="abcdefghijklmnopqrstuvwxyz",caps[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",space[2]=" ";
 for(i=0;i<len;)
   {
     if(s.at(i)=='1')
       {  num=100*(s.at(i)-'0')+10*(s.at(i+1)-'0')+s.at(i+2)-'0';
	  i+=3;
       }
     else
       {  num=10*(s.at(i)-'0')+s.at(i+1)-'0';
	  i+=2;
       }
     if(num==32)
       out.append(space);
     else
       {
	 if(num>=97 && num<=123)
	   cur=small[num-97];
	 else
	   cur=caps[num-65];
	 out.append(cur);
       }

   }
 cout<<out<<endl;
}
int main()
{
 long int tcases;
cin>>tcases;
while(tcases--)
  solver();

return 0;
}

