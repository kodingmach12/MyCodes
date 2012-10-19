#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//It is similar to kadane's Algorithm
int first_Petrol_Pump(int p[],int d[],int n)
{
    int i=0,c=0,petrol_left=0,start=0;
    for(i=0 ; i<n && c<n ; i++ )
    {
        //cout<<" "<<i<<" "<<petrol_left<<endl;
        petrol_left+=p[i];
        if(petrol_left < d[i])
        {
            start=i+1;
            petrol_left=0;
            c=0;
        }
        else{
            petrol_left-=d[i];
            c++;
        }
    }
    while(c<n)
    {
        petrol_left+=p[i%n]-d[i%n];
        if(petrol_left < 0)
            return -1;
        c++;
        i++;
    }
return start;
}


int main()
{
    int petrol[15]={5,4,6,7,4},distance[15]={4,7,6,4,5};
    int n,i=0;
    cin>>n;
    while(i<n)
    {
        //cin>>petrol[i]>>distance[i];
        cout<<" "<<petrol[i]<<" "<<distance[i]<<endl;
        i++;
    }
    int start=first_Petrol_Pump(petrol,distance,n);
    if(start==-1)
        cout<<" No point to start"<<endl;
    else
        cout<<" The first point to start is Petrol Pump No :  "<<(start+1)<<endl;

return 0;
}
