#include<stdio.h>
void swap(char *a,char *b)
{
char temp;
temp=*a,*a=*b,*b=temp;
}
void permute(char* str, int len, int level)
{
    //if last character is reached, print the string
    if(len == 1){
        printf("%s\n", str-level);
        return;
    }
int i;
    for(i=0; i<len  ; i++)
    {
        //swap first charater with the ith character
		//if(str[0]!=str[i])
		{
        swap(&(str[0]), &(str[i]));

        //recursively permute rest of the string
        permute(str+1, len-1, level+1);
        
        //bring first character back to its position
        swap(&(str[0]), &(str[i]));
		}
    }
}

int main()
{
    char str[20];

    //sprintf(str, "abcd");
scanf("%s",str);
printf("the permutations are \n\n");
    permute(str, strlen(str), 0);

    return 0;
	}