#include<iostream>
#include<cstdio>
#include<sstream>
#include<cmath>
#include<cassert>
using namespace std;
void solver()
{
string path;
cin>>path;
long long int finx=0,finy=0,len=path.size(),i=0,j=0;
int curdir=0,flg=0,move=0,prevdir=0,a, dirtable[4][2]={{2,3},{3,2},{1,0},{0,1} },b,dirindex=0;
string dir[8]={ "N","S","W","E","NE","NW","SE","SW" };
double distance=0;
for(i=0;i<len;)
{
a=0LL;
if(isdigit(path.at(i))) 
{
	while(i<len && isdigit(path.at(i))  )
	{
		a= a*10 + path.at(i)-'0';
		i++;
	}
	if(curdir==0)
	   finy+=a;
	else if(curdir==1)
	   finy-=a;
	else if(curdir==2)
	   finx-=a;
	else if(curdir==3)
	   finx+=a;
}
else
{
	b=path.at(i);
        if(b =='L')
	   move=0;
	else 
           move=1;   
	prevdir=curdir;
	curdir=dirtable[curdir][move];
	i++; 
}
}

distance=sqrt((finx*finx)+(finy*finy));
if(finx>0 && finy==0)
dirindex=3;	//east
else if(finx>0 && finy>0)
dirindex=4;    //ne
else if(finx==0 && finy>0)
dirindex=0;   //north
else if(finx<0 && finy>0)
dirindex=5;  //nw
else if(finx<0 && finy==0)
dirindex=1;  //west
else if(finx<0 && finy<0)
dirindex=7;  //sw
else if(finx==0 && finy<0)
dirindex=2;  //south
else if(finx>0 && finy<0)
dirindex=6;  //se
printf("%.1f",distance);
if(distance!=0.0)
	cout<<dir[dirindex];
cout<<endl;
}
int main()
{
int t;
cin>>t;
assert(t>0 && t<=100);
while(t--)
  solver();

return 0;
}

