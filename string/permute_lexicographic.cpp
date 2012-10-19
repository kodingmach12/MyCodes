#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void permute(char* str, int len, int level)
{
    //if last character is reached, print the string
    if(len == 1){
        printf("%s\n", str-level);
        return;
    }
    int i,j;
    char temp;
    for(i=0; i<len  ; i++)
    {
                    //    swap(&(str[0]), &(str[i]));
            if(i)
            {
                temp=str[i];
                for(j=i;j>=1;j--)
                    str[j]=str[j-1];
                str[0]=temp;
            }
            permute(str+1, len-1, level+1);
            if(i)
            {
                temp=str[0];
                for(j=0;j<i;j++)
                    str[j]=str[j+1];
                str[j]=temp;
                  // swap(&(str[0]), &(str[i]));
            }
    }
}
int main()
{
    char str[20];
    scanf("%s",str);
    printf("the permutations are \n\n");
    permute(str, strlen(str), 0);
    return 0;
}
