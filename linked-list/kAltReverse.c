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

void k_reverse(Node *&head,int k)
{
    if(k<1)     return;
    if(!head)   return;
    Node *prev=NULL,*cur=head,*nex=NULL;
    while(cur && k){
        nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;
    }
    head->next=k_reverse(cur);
   head=prev;
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
     cin>>k;
print(head);
k_reverse(head,k);
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



/* Reverses alternate k nodes and
   returns the pointer to the new head node
struct node *kAltReverse(struct node *head, int k)
{
    struct node* current = head;
    struct node* next;
    struct node* prev = NULL;
    int count = 0;

    /*1) reverse first k nodes of the linked list
    while (current != NULL && count < k)
    {
       next  = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }

    /* 2) Now head points to the kth node.  So change next
       of head to (k+1)th node
    if(head != NULL)
      head->next = current;

    /* 3) We do not want to reverse next k nodes. So move the current
        pointer to skip next k nodes
    count = 0;
    while(count < k-1 && current != NULL )
    {
      current = current->next;
      count++;
    }

    /* 4) Recursively call for the list starting from current->next.
       And make rest of the list as next of first node
    if(current !=  NULL)
       current->next = kAltReverse(current->next, k);

    /* 5) prev is new head of the input list
    return prev;
}
*/
