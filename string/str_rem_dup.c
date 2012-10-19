#include<stdio.h>
#include<string.h>
/*
Test Cases:
1   String does not contain any duplicates, e g : abcd
2   String contains all duplicates, e g : aaaa
3   Null string
4   String with all continuous duplicates, e g : aaabbb
*/
void removeDuplicates(char *str) 
{
  if (str == NULL) return;
  int len = strlen(str);
  if (len < 2) return;
  int tail = 1,i,j;
 
  for (i = 1; i < len; ++i) 
  {
	 for (j = 0; j < tail; ++j) 
	 {
      if (str[i] == str[j]) 
		break;
     }
     if(j == tail) 
	 {
      str[tail] = str[i];
      ++tail;
     }
  }
    str[tail] = 0;
}

int main()
{
char str[100];
scanf("%s",str);
removeDuplicates(str);
printf("\nThe new string is \n %s\n",str);
}
