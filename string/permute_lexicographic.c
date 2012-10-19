#include<stdio.h>
#include<string.h>
char s[100];
int cnt =0 ;
void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
void permute(char* s, int i ,const int n)
{
    if(n==i){
        printf("%s\n",s);
        return;
    }
    int j;
    for(j=i;j<=n;j++){
        swap(s+i,s+j);
        permute(s,j,n);
        swap(s+i,s+j);
    }
}


int main()
{
    char str[20];
    scanf("%s",str);
    printf("the permutations are \n\n");
    permute(str,0,strlen(str));
    printf("%d\n",cnt);
    return 0;
}
