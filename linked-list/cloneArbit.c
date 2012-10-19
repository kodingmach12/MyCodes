#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
    struct node *arbit;
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
void sort( Node *&);

/* Write Functions here */
/*
1) Create the copy of node 1 and insert it between node 1 & node 2 in original Linked List, create the copy of 2 and insert it between 2 & 3.. Continue in this fashion, add the copy of N afte the Nth node
2) Now copy the arbitrary link in this fashion
     original->next->arbitrary = original->arbitrary->next;  //TRAVERSE  TWO NODES
This works because original->next is nothing but copy of original and Original->arbitrary->next is nothing but copy of arbitrary.
3) Now restore the original and copy linked lists in this fashion in a single loop.
     original->next = original->next->next;
     copy->next = copy->next->next;
4) Make sure that last element of original->next is NULL.
*/
void cloneArbit(Node* in,Node*& copyHead)
{
    if(!in) return;
    Node *inCur=in,*inNext;
    Node  *copyPrev=NULL,*copyCur=NULL;
    while(inCur)                   // create the copy linked list
    {
        inNext=inCur->next;

        copyCur=newNode(inCur->data);
        copyCur->next=NULL;
        copyCur->arbit=inCur;

        inCur->next=copyCur;
        if(copyPrev){
            copyPrev->next=copyCur;
            copyPrev=copyPrev->next;
        }
        else
            copyHead=copyCur;
        inCur=inNext;
    }
    copyCur=copyHead;
    inCur=in;
    while(copyCur){
        copyCur->arbit = copyCur->arbit->arbit->next;
        copyCur=copyCur->next;
        inCur->next = inCur->next->next->arbit;
        inCur=inCur->next;
    }
}
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

     push_front(head, 7);
     push_front(head, 1);
     push_front(head, 2);
     push_front(head, 6);
     push_front(head, 3);
     push_front(head, 4);
     push_front(head, 5);
     int k;
     int i;
     //cin>>k;


print(head);
cout<<" The reverse order linked list is "<<endl;
print_reverse(head);
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
void split(Node *head, Node *& alist, Node *& blist)
{
    if(!head)    return;
    if(!(head->next))
    {
        alist=head;
        blist=NULL;
        return;
    }

    Node *slowptr=NULL,*fastptr=NULL;
    slowptr=head;
    fastptr=head;

    while(fastptr->next)
    {
        fastptr=fastptr->next;
        if(fastptr->next)
        {
            slowptr=slowptr->next;
            fastptr=fastptr->next;
        }
    }
alist=head;
blist=slowptr->next;
    slowptr->next=NULL;
}
Node* SortedMerge(Node *a, Node *b)
{
    if(a==NULL) return b;
    if(b==NULL) return a;
    Node *result=NULL;
    if(a->data <= b->data)
    {
        result=a;
        result->next = SortedMerge(a->next,b);
    }
    else
    {
        result=b;
        result->next = SortedMerge(a,b->next);
    }
return result;
}
void sort(Node *& head)
{
    if(!head || !(head->next))    return;
    Node *alist=NULL,*blist=NULL;
    split(head,alist,blist);
    sort(alist);
    sort(blist);
head=SortedMerge(alist,blist);
}
