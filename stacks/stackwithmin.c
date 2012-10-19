


/*#include<stdio.h>
typedef struct stacknode
{
int data;
struct stacknode* next;
}Stack;

typedef struct min_node
{
int data;
struct min_node* next;
}Min;


void push(Stack *s,int value)
{

	if(isempty(s))
	{
	Stack temp=(Stack)malloc(sizeof(Stack));
	temp->data=value;
	temp->next=NULL;

	Min temp=(Min)malloc(sizeof(Min));
	Min->data=value;
	Min->next=NULL;
	}
	else
	{
	Stack temp=(Stack)malloc(sizeof(Stack));
	temp->data=value;
	temp->next=s;
	*s=temp;


	}

}

int pop(struct stack s)
{

}

int top(struct stack s)
{

}

int min(struct stack s)
{

}

int isempty(struct stack s)
{

}

int main()
{
Stack *s;



}*/
