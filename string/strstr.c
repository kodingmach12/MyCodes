#include<stdio.h>
char base[100];
char pattern[10];

int xstrlen(char *s)
{
int len=0;
while(*s!='\0')
 {len++;
 s++;
 }
return len;
}

//int xstrstr(char *base,char *pattern)
int xststr()
{
int len1=xstrlen(base);
int len2=xstrlen(pattern);
if(len1<len2)
	return -1;
if(len1==0 || len2==0)
	return -1;
int index=0,i=0,j=0;
for(i=0;i<len1;i++)
{
 if(base[i]==pattern[0])
 {
 index=i;
 for(j=1;j<len2;j++)
 {
	if(base[i]!=pattern[j])
		break;
 }
 if(pattern[j]=='\0')
	return index;
 else
 {	i-=j;
	j=0;
 }
 }
 }
 return -1;
 }

int main()
{
scanf("%s",&base);
scanf("%s",&pattern);
int n=xstrstr();
if(n==-1)
	printf("Pattern not found\n");
//xstrstr(char *str1,char *str2);
}
