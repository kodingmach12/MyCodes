#include<stdio.h>

const int b = 8;

int 
getData(int const ** ptr){
	*ptr = &b;
return 0;
}

int main2()
{
int a = 5;
int *ptra = &a;


printf("a = %d b = %d ptra = %u *ptra = %d\n",a,b,ptra,*ptra);

printf("Error code is %d \n", getData(&ptra) );

printf("a = %d b = %d ptra = %u *ptra = %d\n",a,b,ptra,*ptra);

*ptra = 9;

printf("a = %d b = %d ptra = %u *ptra = %d\n",a,b,ptra,*ptra);

return 0;
}


void getData2(char const* *ptr){

	char* mem = (char*)malloc(10);
	strcpy(mem,"helloUser");

	printf("		ptr = %s\n",*ptr);
	printf("		mem = %s\n",mem);
	*ptr = mem;
	printf("		ptr = %s\n",*ptr);
}

int main()
{
char *ptra = NULL;

printf(" ptra = %s\n",ptra);
	getData2(&ptra);
printf(" ptra = %s\n",ptra);

return 0;
}

