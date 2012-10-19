#include<string.h>
#include<math.h>
#include<limits.h>

int prevprime(int n)
{


}

int nextprime(int n)
{



}


int isprime(int n)
{
int j=2,limit=sqrt(n);
		while(j<=limit)
		{
			if(n%j==0)
				return 0;
			else	
			{	j++;
				continue;
			}
		}
return 1;
}

int myatoi( char* pStr ) 
{ 
  int iRetVal = 0; 
  int iTens = 1;
 
  if ( pStr )
  {
    char* pCur = pStr; 
    while (*pCur) 
      pCur++;
 
    pCur--;
 
    while ( pCur >= pStr && *pCur <= '9' && *pCur >= '0' ) 
    { 
      iRetVal += ((*pCur - '0') * iTens);
      pCur--; 
      iTens *= 10; 
    }
  } 
  return iRetVal; 
} 
int ispalindrome(char *p)
{
int len=strlen(p);
char *start=p,*end=(p+len-1);
while(start<=end)
{
		if(*start==*end)
		{
			start++;
			end--;
			continue;
		}
		else
		{	
			printf("\n %c %c  ",*start,*end);
			return 0;
		}
}
return 1;
}
int main()
{
char p[100];
/*scanf("%s",p);

printf("\n%d\n",myatoi(p));
if(ispalindrome(p))
	printf("\n  is a palindrome \n");
else
	printf("\n  is not a palindrome \n");
	
int num;
scanf("%d",&num);
if(isprime(num))
 printf("\n\nIs a prime");
else	
	printf("\n\nIs not a prime"); 
	*/
printf("\n\t%d\t%d\t%d",INT_MAX,INT_MIN);	
return 0;
}