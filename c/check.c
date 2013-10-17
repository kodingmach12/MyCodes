#include<stdio.h>

int getData(int* ptr){
*ptr = 7;

return 0;
}

int main()
{
int a = 5;
printf("a = %d \n",a);
printf("Error code is %d \n", getData(&a) );
printf("a = %d\n",a);

return 0;
}
