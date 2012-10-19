#include<stdio.h>

struct maxelem
{
int freq;
int value;
};
void findmaxoccur(char *str)
{
int hash[26]={0};
struct maxelem max1;
char *temp=str;
int charvalue;
while(*temp)
{
charvalue=*temp;
hash[charvalue-97]+=1;


}



}
int main()
{
char str[100];
scanf("%s",str);
findmaxoccur(str);
}