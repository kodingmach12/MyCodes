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

Node * k_reverse_helper(Node *head,int k)
{
    if(k<1)     return head;
    // not sure if what will be done if node count is less than k
    if(!head)   return head;
    Node *prev=NULL,*current=head,*nex=NULL;
    int i=k;
    while(current && k)
    {
        nex=current->next;
        current->next=prev;
        prev=current;
        current=nex;
        k--;
    }
    head->next=k_reverse_helper(current,i);
return prev;
}

void k_reverse(Node *&head,int k)
{
    if(k<1)     return;
    if(!head)   return;
    head=k_reverse_helper(head,k);
}
Node* k_alternate_reverse_helper(Node* head, int k)
{
    if(k<1)     return head;
    if(!head)   return head;
    Node *prev=NULL,*current=head,*nex=NULL,*new_head=NULL;
    int i=k;
    while(current && i)
    {
        nex=current->next;
        current->next=prev;
        prev=current;
        current=nex;
        i--;
    }
    i=k;
    new_head=prev;
    head->next=current;
    while(current && i)
    {
        prev=current;
        current=current->next;
        i--;
    }
    prev->next=k_alternate_reverse_helper(current,k);
return new_head;
}

void k_alternate_reverse(Node *&head, int k)
{
    if(k<1)     return;
    if(!head)   return;
    head=k_alternate_reverse_helper(head,k);
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
cout<<" Linked list : "<<endl;
print(head);
reverse(head);
cout<<" Linked list  after reversal : "<<endl;
print(head);
//k_reverse(head,k);
k_alternate_reverse(head,k);
//cout<<" Linked list  after "<<k<<"-reversal : "<<endl;
cout<<" Linked list  after "<<k<<" alternate-reversal : "<<endl;
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
    Node *prev=NULL,*current=head,*nex=NULL;

    while(current)
    {
        nex=current->next;
        current->next=prev;
        prev=current;
        current=nex;
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
