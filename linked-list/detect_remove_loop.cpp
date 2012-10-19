#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
}Node;

// All Edge cases checked

Node* newNode( int val );
void print( Node * );
void push_front( Node *&, int );
void push_back( Node *&, int );
void pop_front( Node *& );
void pop_back( Node *& );
int size( Node * );

void detect_and_remove_Loop(Node *head)
{
    if(head==NULL)  return;
    Node *slow=head,*fast=head;
    bool res=false;
    while(1)
    {
        fast=fast->next;
        slow=slow->next;
        if(fast->next)
            fast=fast->next;
        if(slow->next == head)
        {
            res=true;
            break;
        }
        if( !fast  ||  fast->next==NULL)
        {
            res=false;
            break;
        }
        if( fast == slow)
        {
            res=true;
            break;
        }

    }
    if(res==false)
        return;
    else{
        cout<<" Loop exists at "<<slow->data<<endl;
    }
    Node *temp=head,*prev=slow;
    if(slow->next==head)
        slow->next=NULL;
    else
    {
        while(temp!=slow)
        {
            prev=slow;
            slow=slow->next;
            temp=temp->next;
        }
        prev->next=NULL;
    }
}


/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    int k,i;
     push_front(head, 1);
     push_front(head, 2);
     push_front(head, 3);
     push_front(head, 4);
     push_front(head, 5);
     push_front(head, 6);
     push_front(head, 7);

     //cin>>k;
     print(head);
     Node *temp=head;
     while(temp->next)
        temp=temp->next;
     temp->next=head->next->next;
     //printList(head);
     detect_and_remove_Loop(head);
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
