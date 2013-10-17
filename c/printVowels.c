#include <stdio.h>
#include <stdlib.h>
#include<string.h>
extern "C" {
int main()
{
const char* instr = "hello david how are you doing";
const char* vowels = "aeiou";
const char* pch = NULL;
printf(" vowels in %s : \n", instr);
pch = strpbrk(instr,vowels);
while(NULL != pch){
printf(" %c ",*pch);
pch = strpbrk(pch+1,vowels);
}
printf("\n");
return 0;
}
}
