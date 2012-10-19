#include<stdio.h>
int ispalin(int a,int *b)
{
    if(a==0)
        return 1;
    if(ispalin(a/10,b) &&  (a%10 == ((*b)%10)  ) )
    {
         *b=(*b)/10;
        return 1;
    }
    else
        return 0;
}
int ispalindrome(int a)
{
    if(a<0)
        return 0;
    return ispalin(a,&a);
}

int main()
{
    int n;
    scanf("%d",&n);
    if()
    if(ispalindrome(n))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

return 0;
}
