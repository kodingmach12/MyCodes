#include<stdio.h>
#include<string.h>
#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",n)
void solver()
{
  int n,i,j,num[4]={0},res=0;
  int prod[4]={4096,256,16,1};
  char s[4][10];
  char code[10][7]={ "black","brown","red","orange","yellow","green","blue","violet","gray","white"};
 
for(i=0;i<4;i++)
   {   ss(s[i]);
     for(j=0;j<10;j++)
       if( strcmp(s[i],code[j]) == 0)
	 {	 num[i]=j;
	   break;
	 }
     
   }
 for(i=0;i<4;i++)
   res+=num[i]*prod[i];
 printf("%d",res);
 while(j--)
   printf("0");
 printf(" Guntur");
}

int main()
{
  solver();
return 0;
}
