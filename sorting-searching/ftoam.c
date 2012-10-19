#include<stdio.h>
int main()
{
float num;
char str[10];
scanf("%f",&num);
str=ftoa(num);
printf("\nthe string is %s",str);

return 0;
}
