#include<stdio.h>

f(char *x) {
	x++;
	*x = ‘a’;
}

int main() {

char *str = "hello";
f(str);
printf("%s", str);
return 0;
}
