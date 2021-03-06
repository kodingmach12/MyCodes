#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
}Node;

Node* newNode( int val );
void print( Node * );
void push_front( Node *&, int );
void push_back( Node *&, int );
void pop_front( Node *& );
void pop_back( Node *& );
int size( Node * );
void reverse(Node *&);
void print_reverse(Node*);

Node * pairswap_helper(Node *head)
{
Node *prev=NULL,*temp1=head,*temp2=head->next;

if(!temp2)
	return head;
head=temp2;
	while( temp1 && ( temp2=temp1->next ) )
	{
		if(prev!=NULL)
			prev->next=temp2;
		prev=temp1;
		temp1->next=temp2->next;
		temp2->next=temp1;
		temp1=temp1->next;
	}
	return head;
}
void pairswap(Node *&head)
{
    if(!head || !(head->next))  return;
    head=pairswap_helper(head);
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

     push_front(head, 1);
     push_front(head, 2);
     push_front(head, 3);
     push_front(head, 4);
     push_front(head, 5);
     push_front(head, 6);
     push_front(head, 7);
     int k;
     int i;
     //cin>>k;


print(head);
cout<<" Print in reverse order "<<endl;
print_reverse(head);
pairswap(head);
cout<<" Print after pair swap "<<endl;
print(head);
return 0;
}

Node* newNode(int val)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp!=NULL)
    {
          temp->data=val;
          temp->next=NULL;
    }
    return temp;
}

void print(Node *head)
{
    if(head)
    {
        while(head)
        {
            cout<<" "<<head->data;
            head=head->next;
        }
        cout<<endl;
    }
}

void push_front( Node *&head, int  val)
{
    Node* temp = newNode(val);
    temp->next = head;
    head=temp;
}

void push_back(Node *&head_ref,int data)
{
    Node *temp=NULL;
    Node *p=newNode(data);
    if(!head_ref)
            head_ref=p;
    else
    {
        temp=head_ref;
    while(temp->next)
        temp=temp->next;
    temp->next=p;
    }
}
int size(Node *head)
{
    int len=0;
    while(head)
    {
        len++;
        head=head->next;
    }
return len;
}
void reverse(Node *&head)
{
    if(!head || !(head->next))  return;
    Node *prev=NULL,*cur=head,*nex=NULL;

    while(cur)
    {
        nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;
    }
head=prev;
}
void print_reverse(Node *head)
{
    if(!head)   return;
    print_reverse(head->next);
    cout<<" "<<head->data;
}
