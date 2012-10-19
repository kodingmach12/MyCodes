#include<stdio.h>
/*ALGO ===  add how to handle bad expression
Initialise an empty stack S;
Scan the infix expression from left to right in ch;
If  ch is an operand,add it to the postfix string
If  ch is an operand,
	If the stack is empty,add it to the stack;
	else 
		If  scanned character has higher precedence over the top of the stack
			push it to the top of the stack
		else
			pop the stack until an element with lower precedence than current char is not found and 
			keep adding it to the postfix string
*/
typedef struct stack
{
char data;
struct stack *next;
}Stack;
Stack CreateStack(char data);
int isopnd(char c)
{
return ('c'>=48 && 'c'<58);
return 0;
};
int hashighprecedence(char a,char b)
{
char prectable[]={/,*,+,-};
}

void intopost(char inexp[],char postexp[])
{
	char *t1=inexp,*t2=postexp,c;
	Stack s=CreateStack(*t1);
	if(isempty(t1))
		printf("\nWarning :Bad String Input ");
	while((c=*t1)!='\0')
	{
		if(isopnd(c))	
			*t2++=c;
		else
			if(hashighprecedence(c,S.top())
				S.push(*t1);
			else
				while(hashighprecedence(c,S.top))
					*t2++=S.pop();
	}
}


int main()
{
char inexp[100],postexp[100];
scanf("%s",inexp);
printf("PostFix String is :- \n \t%s \n",postexp);

}