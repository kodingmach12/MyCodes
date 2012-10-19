#include<stdio.h>
typedef struct node Node
{
int data;
struct node *link;
};

Node* create(int value)
{
Node* temp=(Node*)malloc(sizeof(Node));
temp->data=value;
temp->link=NULL;
}
void append(Node* head,int value)
{
	if(head==NULL)
	{
		head=create(value);
		return;
	}
	Node* temp=(Node*)malloc(sizeof(Node));
	if(temp)
	{
		temp->data=value;
		temp->link=NULL;
	}
	Node *temp2=head;
	while(temp2->link!=NULL)
		temp2=temp2->link;
	temp2->link=temp;
}
int main()
{
Node *num1=NULL,*num2=NULL;
char c;
while(scanf("%c",&c)!=' ')
{

}

}