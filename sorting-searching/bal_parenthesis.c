#include<stdio.h>
void _printpar(int pos,int open,int close,int n)
{
    static char str[200];
    if(close==n)
    {
        printf("%s\n",str);
        return;
    }
    else
    {
        if(open<n)
        {
            str[pos]='{';
            _printpar(pos+1,open+1,close,n);
        }
        if(close< open)
        {
            str[pos]='}';
            _printpar(pos+1,open,close+1,n);
        }
    }
}
void printpar(int n)
{
int open=0,close=0,pos=0;
_printpar(pos,open,close,n);
}

int main()
{
int n=0;
scanf("%d",&n);
printpar(n);

return 0;
}
