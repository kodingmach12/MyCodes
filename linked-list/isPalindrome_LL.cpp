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

bool compareLists(Node *alist, Node *blist)
{
    if(!alist && !blist)    return true;
    if(!alist || !blist)    return false;
    while(alist && blist)
    {
        if(alist->data == blist->data)
        {
            alist=alist->next;
            blist=blist->next;
        }
        else
            return false;
    }
    if(!alist && !blist)    return true;
return false;
}

bool is_palindrome(Node *head)
{
    if(!head || !(head->next))      return true;
    Node *slow_ptr=head,*fast_ptr=head,*middle=NULL;
    bool single_node;
    while(fast_ptr && fast_ptr->next)
    {
        fast_ptr=fast_ptr->next;
        single_node=false;
        if(fast_ptr->next)
        {
            single_node=true;
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next;
        }
    }
    Node *blist = slow_ptr->next;
    Node *alist = head;
    slow_ptr->next=NULL;
    reverse(alist);
    if(single_node)
    {
        middle=alist;
        alist=alist->next;
    }
    print(alist);
    print(blist);
    bool res=compareLists(alist,blist);
    if(single_node)
    {
        middle->next=alist;
        alist=middle;
    }
    reverse(alist);
    Node *temp=alist;
    while(alist->next)
        alist=alist->next;
    alist->next=blist;
return res;
}


int main()
{
     struct node* head = NULL;
     push_front(head, 1);
     push_front(head, 2);
     push_front(head, 3);
     push_front(head, 4);
     push_front(head, 4);
     push_front(head, 3);
     push_front(head, 2);
     push_front(head, 1);
     int k;
     int i;
     //cin>>k;

cout<<" List : "<<endl;
print(head);
cout<<" List : "<<endl;
print_reverse(head);

if(is_palindrome(head))
    cout<<" Palindrome"<<endl;
else
    cout<<" Not Palindrome"<<endl;
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
        cout<<endl;
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

