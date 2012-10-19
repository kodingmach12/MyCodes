#include<iostream>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
//#include<conio.h>
using namespace std;
#define fill(a,v) memset(a, v, sizeof a)
typedef long LL;
LL N,M,x,y,z,w,curind,curval,maX,miN,d;

void print(LL change[][2])
{
cout<<endl;
for( int i=0;i<2*M;i++)
cout<<change[i][0]<<" "<<change[i][1]<<endl;
cout<<endl;
}
void updateMinMax()
{
if(curval < miN)
miN = curval;
else if(curval > maX)
maX = curval;
}
void merge(LL ar[][2], int s, int mid, int e, int l)
{
int tmp[l][2];
int i=0,j=s,k=mid+1;
while(j<=mid || k<=e)
{
if(j>mid)
{
while(k<=e)
{
tmp[i][0]=ar[k][0];
tmp[i][1]=ar[k][1];
i++;k++;
}
break;
}
else if(k>e)
{
while(j<=mid)
{
tmp[i][0]=ar[j][0];
tmp[i][1]=ar[j][1];
i++;j++;
}
break;
}
else
{
if(ar[j][0]<=ar[k][0])
{
tmp[i][0]=ar[j][0];
tmp[i][1]=ar[j][1];
i++;j++;
}
else
{
tmp[i][0]=ar[k][0];
tmp[i][1]=ar[k][1];
i++;k++;
}
}
}
for(i=0;i<=(e-s);i++)
{
ar[s+i][0]=tmp[i][0];
ar[s+i][1]=tmp[i][1];
}
}
void merge_sort(LL ar[][2], int s, int e, int l)
{
if(s==e || e>=l)
return;
int mid=s+(e-s)/2;
merge_sort(ar,s,mid,l);
merge_sort(ar,mid+1,e,l);
merge(ar,s,mid,e,l);
}
void solve()
{
cin>>N>>M;
LL change[2*M][2];
fill(change,0);
//cout<<"its ok !!"<<endl;
for(int i=0;i<M;i++)
{
scanf("%ld%ld%ld%ld",&w,&x,&y,&z);
if(w==1){
change[2*i][0] = x-1;
change[2*i][1] -= z;
change[2*i+1][0] = y;
change[2*i+1][1] += z;
}
else
{
change[2*i][0] = x-1;
change[2*i][1] += z;
change[2*i+1][0] = y;
change[2*i+1][1] -= z;
}
}
merge_sort(change,0,2*M-1,2*M);
for(int i=0;i<2*M-1;i++)
{
if(change[i][0]==0){
change[i][1]=0;
change[i][0]=-1;
}
if(change[i][0] == change[i+1][0])
{
change[i+1][1] += change[i][1];
change[i][0] = -1;
change[i][1]=0;
}
}

for(int i=2*M-2;i>=0;i--)
change[i][1] += change[i+1][1];

maX = change[2*M-1][0]+change[2*M-1][1];
miN = maX;
curind=N;
curval=N;
d=0;

for( int i=2*M-1;i>=0;i--)
{
if(change[i][0]!= -1)
{
if(curind>change[i][0])
{
curval = curind+d;
updateMinMax();
curval=change[i][0]+1+d;
updateMinMax();
curind=change[i][0];
}
if(curind == change[i][0] ){
curval=change[i][0]+change[i][1];
updateMinMax();
d=change[i][1];
}
}
}
if(curind>1)
{
curval = 1+d;
updateMinMax();
}
LL range= maX-miN;
printf("%ld\n",range);
}
int main()
{
int tcases,i;
cin>>tcases;
for(i=1;i<=tcases;i++)
{
solve();
}
//getch();
return 0;
}
