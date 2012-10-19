#line 5 "DengklekMakingChains.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class DengklekMakingChains{
	public:
int maxBeauty(vector <string> c) 
{
	vector< string >:: iterator i;
	int left=0,mid=0,right=0,maxl=0,maxr=0,sin=0,maxsin=0,sidel=0,sider=0; 	string chain;
for(i=c.begin();i!=c.end();i++) 
  {	left=sin=right=0;
	chain= (*i);
          if(chain.at(0)=='.' && isdigit(chain.at(1)) && chain.at(2)=='.') 	 {
		sin= chain.at(1)-'0';	
		if(sin>maxsin) 	  maxsin=sin;	 } 
	  else if(chain.at(0)=='.' && chain.at(1)=='.' && isdigit(chain.at(2)))  {
		left=chain.at(2)-'0';
		if(left>maxl) maxl=left;  	  } 
	  else if(chain.at(0)=='.' && isdigit(chain.at(1)) && isdigit(chain.at(2)))  {
		left=chain.at(1)-'0' + chain.at(2)-'0';
		if(left>maxl) maxl=left;  	  }
          else if( isdigit(chain.at(0)) && isdigit(chain.at(1)) && isdigit(chain.at(2)) )
  	        mid+=chain.at(0)-'0'+ chain.at(1)-'0' + chain.at(2)-'0';
	  else if(isdigit(chain.at(0))  && isdigit(chain.at(1)) && chain.at(2)=='.' )  	   {
 	       right=chain.at(1)-'0' + chain.at(0)-'0';
	       if(right>maxr) maxr=right;  	  }
          else if(isdigit(chain.at(0))  && chain.at(1)=='.' && chain.at(2)=='.' )   	  {
	       right=chain.at(0)-'0';
	       if(right>maxr) maxr=right; 	  }
          else if(isdigit(chain.at(0))  && chain.at(1)=='.' && isdigit(chain.at(2)) )   	  {
                  right=chain.at(0)-'0';
		  left=chain.at(2)-'0';
	          if( left > sidel)
		    sidel=left;
		  if(right > sider)
		    sider=right;
		    
	  }
}
 cout<<endl<<" L "<<maxl<<" Mid "<<mid<<" R "<<maxr<<" Single "<<maxsin<<" Sidel "<<sidel<<" Sider "<<sider<<endl;
 if(sidel-maxl > sider-maxr && sidel>maxl )
   maxl=sidel;
 else if( sider>maxr )
   maxr=sider;
int tot=maxl+mid+maxr;
int final= (tot > maxsin ? tot : maxsin);
 if(sidel+sider > final )
   final=sidel+sider;   // use brute force to determine if sidel and sider are two different chains
return final;
}
};
int main()
{
DengklekMakingChains A;
vector<string> a;
string chain;
int len,max;
cin>>len;
while(len--){
        cin>>chain;
        a.push_back(chain);
}
max=A.maxBeauty(a);
cout<<max<<endl;
return 0;
}




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
