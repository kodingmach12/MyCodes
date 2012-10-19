#include<stdio.h>
#include<string.h>
    //Write code for reverse RLE
void reverse(char *start,char *end)
{
    char temp;
    while(start<end)
    {
        temp=*start;
        *start++=*end;
        *end--=temp;
    }
}

void itoa(int n,char *num)
{
    int i=0,len=0;
    while(n)
    {
        i=n%10;
        num[len]=i+48;
        len++;
        n/=10;
    }
    reverse(num,num+len-1);
    num[len]='\0';
}

void torle(char *str)
{   int i=0,j=0,k=0,cnt=1;
    char cur_char=str[0],num[100];
    while(str[j+1]!='\0')
    {
            cnt=1;
            while(str[j+1]==cur_char && str[j]!='\0'){
                j++;
                cnt++;
            }
            str[i++]=cur_char;
            if( cnt>9 ){
                itoa(cnt,num);
                k=0;
                while(num[k]) str[i++]=num[k++];
            }
            else if( cnt>1 && cnt<10 )
                str[i++]= cnt+'0';
            printf("\ncnt = %d num = %s i = %d j = %d",cnt,num,i,j);
        j++;
        if(str[j]!='\0') cur_char=str[j];
    }
    if(i!=0){
        if(cnt==1)
        str[i++]=cur_char;
        str[i]='\0';
    }
}
int main()
{
    char str[100];
     printf("Enter a string of chars(No Spaces)\n");
    scanf("%s",str);
//gets(str);
    torle(str);
    char a='1';
    //printf("\n1=%d\n",a);
    printf("The encoded string is \t");
    printf("%s\n",str);
return 0;
}
