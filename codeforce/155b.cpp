#include <iostream> 
#include <vector> 
#include <cmath> 
#include <algorithm> 

using namespace std; 
#define forall(i,a,b) for(i=a;i<b;i++)

void solver()
{
long  int n,i=0,j=0,cardsleft=1,points=0;
 cin>>n;
 pair<int ,int> t;
 vector< pair <int,int> > v;
 forall(i,0,n)
   {
     cin>>t.first>>t.second;
     swap(t.first,t.second);
     v.push_back(t);
   }
 sort(v.begin(),v.end());
 vector< pair <int,int> > :: iterator itr;
 for(itr=v.end()-1;itr>=v.begin();itr--)
   {
     points+=(*itr).second;
     cardsleft+=(*itr).first;
     cardsleft--;
     if(cardsleft==0)
       break;

   }
 cout<<points<<endl;
}
int main()
{
 solver();
return 0;
}

