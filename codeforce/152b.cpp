#include <iostream> 
#include <cmath> 
using namespace std; 
int valid(int x,int y,int row,int col){
  return (x>=1 && y>=1 && x<=row && y<=col);
}
void solver()
{
  long long  int n,m,cx,cy,k,i=0LL,tp=0LL,prevtp=0LL;
  cin>>n>>m>>cx>>cy>>k;
 long long int dx[k],dy[k];
 float slope=0.00;
  while(i<k)
   {  cin>>dx[i]>>dy[i];
     i++;
   }
 cx--;
 cy--;
 n--;
 m--;
 // cout<<slope<<endl;
 for(i=0;i<k;i++)
   {prevtp=tp;
     if(dy[i]==0)
       {
	 if(dx[i]<0)
	   tp+= -cx/dx[i];
	 else
	   tp+=(n-cx)/dx[i];
       }
     else if(dx[i]==0)
       {
	 if(dy[i]<0)
	   tp+= -cy/dy[i];
	 else
	   tp+=(m-cy)/dy[i];
       }
     else
       {
	  slope=(float)dy[i]/(float)dx[i];
      if(slope>0)
	 {
	   if(dx[i]>0 && dy[i]>0)
	     { if(dy[i]>dx[i])
		 tp+=(m-cy)/dy[i];
	       else if(dy[i]<dx[i])
		 tp+=(n-cx)/dx[i];
	       else if(dy[i]==dx[i])
		 {
  		   if(cx>cy)
		     tp+=(n-cx)/dx[i];
                   else if(cx<cy)
		      tp+=(m-cy)/dy[i];
	     	   else if(cx==cy)
		     tp+=( (n<m) ? (n-cx)/dx[i]: (m-cy)/dy[i] );

		 }
	     }
	   else
	     { if(dy[i]<dx[i])  //neg slope changes the condition
		 tp+=-cy/dy[i];
	       else if(dy[i]>dx[i])
		 tp+=-cx/dx[i];
	       else if(dy[i]==dx[i])
		 tp+=( (cx<cy) ? (-cx/dx[i]): (-cy/dy[i]) );
	     }
	 }
       else if(slope<0)
	 {
	   if(dx[i]<0 && dy[i]>0)
	     { 
	       if(dx[i]>-dy[i])
		 tp+=(m-cy)/dy[i];
	       else if(dx[i]<-dy[i])
		 tp+=-cx/dx[i];
	       else if(dy[i]== -dx[i])
		 tp+=((cx>cy)?(cx-n)/dx[i]:(m-cy)/dy[i]);
	     }
	   else if(dx[i]>0 && dy[i]<0 )
	     {
	       if(dx[i]>-dy[i])
		 tp+=(n-cx)/dx[i];
	       else if(dx[i]<-dy[i])
		 tp+=-cy/dy[i];
	       else if(dy[i]== -dx[i])
		 tp+=((cx<cy)?(n-cx)/dx[i]:(cy-m)/dy[i]);

	     }
	 }
       }
     cx+=(tp-prevtp)*dx[i]; //new values 
     cy+=(tp-prevtp)*dy[i];
     cout<<"slope "<<slope<<" tp "<<tp<<" cx "<<cx<<" cy "<<cy<<" Slope "<<slope<<endl;
   }
 cout<<tp<<endl;	     
}
int main()
{
   int tcases;
   cin>>tcases;
   while(tcases--)
    solver();
return 0;
}

