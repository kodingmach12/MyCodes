#include<stdio.h>
void reverse(char *s)
{
int len=strlen(s);
char *start=s,*end=(s+len-1);
char temp;
while(start<end)
{
temp=*start;
*start++=*end;
*end--=temp;
}
}
struct result
{
int len;
int end_index;
};

struct result lcs(char *s1,char *s2)
{
//int size1=strlen(s1);
//int size2=strlen(s2);
int i=0,j=0,k=0,len=0;
struct result max;
max.len=0;
max.end_index=-1;
for(i=0;s1[i]!='\0';i++)
{
	len=0;
	for(k=i,j=0;s2[i]!='\0' && s1[k]!='\0';)
	{
		if(s1[k]==s2[j])
		{
			len++;
			if(len>max.len)
			{	
				max.len=len;
				max.end_index=j;
			}
		}
		else
			len=0;
		
		j++;
		k++;
	}
}
for(i=0;s2[i]!='\0';i++)
{
	len=0;
	for(k=i,j=0;s1[j]!='\0' && s2[k]!='\0';)
	{
		if(s2[k]==s1[j])
		{
			len++;
			if(len>max.len)
			{	
				max.len=len;
				max.end_index=k;
			}
		}
		else
			len=0;
		
		j++;
		k++;
	}
}
			
return max;
}

int main()
{
char s1[5000],s2[5000];
scanf("%s",s1);
strcpy(s2,s1);
reverse(s1);
printf("\n%s",s1);
printf("\n%s",s2);

struct result res;
res=lcs(s1,s2);
printf("\nThe length of LCSusbstring is %d and the end index is %d-->",res.len,res.end_index);
int i=res.end_index-res.len+1;
for(;i<=res.end_index;i++)
{
	printf("%c",s2[i]);

}


return 0;
}
