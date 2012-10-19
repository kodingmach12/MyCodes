#include <cstring>
#include <string.h>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solver()
{
  int t,n,i,j,k,cnt;
  cin>>t>>n;
  string seq,a,b,end="0";
  vector< string > v;
  int arr[t];
  for(i=0;i<t;i++)
    arr[i]=0;
  i=0;
  while(i++<t)
    {
     cin>>seq;
     if(strcmp(seq,end)==0)
        break;
     v.push_back(seq);
    }
  vector< string > :: iterator itr=v.begin(),jtr=v.begin();
  for(itr=v.begin();itr!=v.end();itr++)
    {cnt;
      a=(*itr);
      for(jtr=itr+1;jtr!=v.end();jtr++)
	{
	  //	  if((*itr).at(0),(*jtr).at(O) && (*itr).at(n-1)!=(*jtr).at(n-1))
	  b=(*jtr);
	    if(strcmp(a,b)==0)
	      cnt++;
	}
      arr[cnt]=cnt;
    }
  for(i=0;i<t;i++)
    cout<<arr[i]<<endl;
}
int main()
{
  solver();

return 0;
}

