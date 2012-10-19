#include<stdio.h>
#define true 1
#define false 1
typedef struct node
{
struct node* link;
char data;
}Node;

Node* kreverse(Node *head,int k,Node **head2)
{
Node *cur=head,*pre=NULL,*next;

	while(cur!=NULL && k!=0)
	{
		next=cur->link;
		cur->link=pre;
		pre=cur;
		cur=next;
		k--;
	}
*head2=next;
return cur;
}

int ispalindrome(Node *head)
{
Node *slow=head,*fast=head;
Node *hd1,*hd2;
int cnt=1;
	while(slow->link!=NULL)
	{
		slow=slow->link;
		cnt++;
	}
	hd1= kreverse(head,cnt/2,&hd2);
Node* temp1=hd1,*temp2=hd2;
//printf("\nthe ll1 is\t");
while(temp1!=NULL)
{	printf("%c",temp1->data);
	temp1=temp1->link;
}
//printf("\nthe ll2 is\t");
while(temp2!=NULL)
{	printf("%c",temp2->data);
	temp2=temp2->link;
}
temp1=hd1;
temp2=hd2;

if(cnt%2)
 temp1=temp1->link;
while(temp1->link && temp2->link)
{
	if(temp1->data == temp2->data)
	{	temp1=temp1->link;
		temp2=temp2->link;
		}
	else
		break;
}
if(temp1->link == NULL && temp2->link == NULL)
	return 1;
return 0;
}

Node *createList(char *s)
{
Node *temp,*pre,*head;
head=(Node *)malloc(sizeof(Node));
head->data=*(s++);

pre=head;
while(*s)
{
	temp=(Node *)malloc(sizeof(Node));
	temp->data=*(s);
	temp->link=NULL;
	pre->link=temp;
	pre=temp;
	s++;
	}
return head;
}

int checkPalindrom (struct node **left, struct node *right) 
{
  if (! right)
  { /* stop recursion here */
    return true;
  }
 
  int isp = checkPalindrom(left, right->link);
  if (isp == false)
    return false;
 
  int isp1 = (right->data == (*left)->data);
  *left = (*left)->link; /* save next pointer */
 
  return isp1;
}

int main()
{
char s[100];
scanf("%s",s);
printf("%s",s);
Node *p=createList(s);
Node *tmp=p;

/*printf("\nThe created linked list is -->\n");
while(tmp!=NULL)
{	printf("%c",tmp->data);
	tmp=tmp->link;
}*/

if(ispalindrome(p))
	printf("\nThe %s is palindrome----1",s);
else
	printf("\nNot a Palindrome----1");

if(checkPalindrom(&p,p))
	printf("\nThe %s is palindrome---2",s);
else
	printf("\nNot a Palindrome---2");

return 0;
}
