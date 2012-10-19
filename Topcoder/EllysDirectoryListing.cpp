// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysDirectoryListing.cpp"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
class EllysDirectoryListing {
	public:
  vector <string> getFiles(vector <string> f){
    vector< string > :: iterator i=f.end(),f1=f.end()-1,f2=f.end()-2;
	  //  string cur(".");
	  //  string par("..");
	  int len=f.size();
    
	  string l1= *(i-1);
	  string l2= *(i-2),t;
	  if( (l1=="."|| l1==".." )  && (l2=="." ||  l2==".." ))
	    return f;
	  int j,flg=0;
	  i=f.begin();
	  for(j=0;j<len-2;j++)
	    {
	      if( *(i+j)=="." || *(i+j)== ".." )
		{
		  if(flg==0)
		    { 
		      t=*(i+j);
		      *(i+j)=*f1;
		      *f1=t;//swap(*(i+j),*f1);
		      flg=1;
	  if(*f1=="." || *f1=="..")
	    j--;

		    }
		  else if(flg==1) 
		    {  //swap(*(i+j),f2);
		      t=*(i+j);
		      *(i+j)=*f2;
		      *f2=t;
		      flg=2;
		    }
		}
	      if(flg==2) break;
	      
	    }
	  return f;
  }
};
