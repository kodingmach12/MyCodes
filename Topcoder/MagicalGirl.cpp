// BEGIN CUT HERE

// END CUT HERE
#line 5 "MagicalGirl.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class MagicalGirl {
	public:
double maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain) {
if(M==0 || M==1)
   return 0.0000;
cout<<"IN"<<endl;
double pointsleft=M;
vector< double  > w;
vector<int>::iterator maxit=max_element(day.begin(),day.end());
int maxwit= *maxit,tdays=day.size(),twitches=0,i,j;
double dayslived=0;
for(i=1;i<=maxwit;i++){
pointsleft--;
if(!pointsleft)
  break;
dayslived++;
  w.clear();
  for(j=0;j<tdays;j++) 
  {
 	 cout<<day[j]<<" "<< i<<endl;
 	 if(day[j]==i)
        {
	      double   prwin =win[j]/50;
	      double  totalgain	= (prwin-1.0000)*gain[j];	
		cout<<"  IN2 "<<totalgain;
	      w.push_back(totalgain);
	}
   }
   sort(w.begin(),w.end());
   reverse(w.begin(),w.end());
   twitches=w.size();	
   cout<<"Twitches"<<twitches<<"\n";
   for(j=0;j<twitches;j++)   
   {
   cout<<w[j]<<endl;
   if(w[j] > 0 )
     pointsleft+=w[j];  
   if(pointsleft>=M){
		pointsleft=M;
	break;
  }
   }
		
	}

return (dayslived+pointsleft);
}
};
int main()
{
 MagicalGirl G; 
 int M;
 cin>>M;
 vector<int>day;
 vector<int>win;
 vector<int>gain;
int n,i=0,elem;
cin>>n;


 while(i!=n)
{
cin>>elem;
day.push_back(elem);
i++;
}
i=0;
 while(i!=n)
{
cin>>elem;
win.push_back(elem);
i++;
}
i=0;
 while(i!=n)
{
cin>>elem;
gain.push_back(elem);
i++;
}

double res=G.maxExpectation(M,day,win,gain);
cout<<"Max Days To Live "<<res<<endl;
return 0;
}

