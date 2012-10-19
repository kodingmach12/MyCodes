#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void solver()
{
char  s[1000];
 scanf("%s",s);
 char  out[1000],cur,ch[2];
 int len=strlen(s),num;
 int i=0,j=0;
 for(i=0;i<len;)
   {
     if(s[i]=='1')
       {  num= 100*(s[i]-'0') + 10*(s[i+1]-'0') + s[i+2]-'0' ;
	  i+=3;
	  itoa(num,ch,10);
	  //ch=(char)num;
	  out[j++]=ch[0];
       }
     else
       {  num=10*(s[i]-'0') +  s[i+1]-'0';
	  i+=3;
	  itoa(num,ch,10);
	  //ch=num;
	  out[j++]=ch[0];
       }
   }
 printf("%s\n",out);

}
int main()
{
int tcases;
 scanf("%d",&tcases);
while(tcases--)
  solver();

return 0;
}

