#include<stdio.h>
#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s",n)

void strcrunch(char *,int);
void solver()
{
char a[100],b[100],str[][15]={ "FRIENDS" , "LOVE" , "ADORE" , "MARRIAGE" , "ENEMIES" , "SISTER/BROTHER" }, s[]= "FLAMES";
ss(a);
ss(b);
int alen=0,blen=0, hash1[26]={0},hash2[26]={0},i=0,flen=6;
	while(a[i]!='\0')
	 {
		hash1[a[i]-65]++;
		i++;
	}
	alen=i;
	i=0;

	while(b[i]!='\0') 
	{
		hash2[b[i]-65]++;
		i++;
	}
	blen=i;
	int common=0;
	for(i=0;i<26;i++)
	{
	if(hash1[i]!=0 && hash2[i]!=0)
		common+= (hash1[i]<hash2[i]?hash1[i]:hash2[i]);
	}
	int t=(alen+blen-2*common);
//	printf("%d\n",t);
int prev=0,k=0;
for(i=0;i<5;i++)
{
k=(t-prev)%flen;
if(!k)
{
	prev=0;
	strcrunch(s,flen);
}
else
{
	prev=flen-k;
	strcrunch(s,k);
}
//		printf("%s	k:%d	prev:%d	flen:%d\n",s,k,prev,flen);
flen--;
}
	for(i=0;i<6;i++)
	      if(*s == **(str+i))
		printf("%s\n",str[i]);
}
void strcrunch(char *str,int pos)
{

	int i=0;
	for(i=pos-1;str[i]!='\0';i++)
		str[i]=str[i+1];

}

int main()
{
int tcases=0;
scanf("%d",&tcases);
    while(tcases--)
	solver();
return 0;
}
