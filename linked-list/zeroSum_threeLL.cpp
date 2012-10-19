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
void sort( Node *&);

/* Write Functions here */
bool find_zero_sum(Node *a, Node *b, Node *c, Node *&t1, Node *& t2, Node *& t3 )
{
    sort(a);
    sort(b);
    sort(c);
    reverse(c);
cout<<endl<<" Nodes in sorted order "<<endl;
cout<<" a :";
print(a);
cout<<" b :";
print(b);
cout<<" c :";
print(c);
    Node *aptr,*bptr,*cptr=c;
    int sum=0;
    for(aptr=a; aptr && cptr; aptr=aptr->next)
    {
       // cptr = c ;
        for(bptr=b; bptr && cptr; bptr=bptr->next)
        {
            sum = -(aptr->data + bptr->data);
          //  cout<<" sum to be found : "<<sum<<" cptr : "<<cptr->data<<endl;
            while(cptr && cptr->data >= sum)
            {
                if(cptr->data == sum ){
                    t1=aptr;
                    t2=bptr;
                    t3=cptr;
                    return true;
                }
                cptr=cptr->next;
            }

        }
    }
return false;
}
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
     Node* head = NULL;
     push_front(head, -5);
     push_front(head, -9);
     push_front(head, -2);
     push_front(head, 6);
     push_front(head, -3);
     push_front(head, 4);
     push_front(head, 5);

     Node* b = NULL;
     push_front(b, -7);
     push_front(b, -1);
     push_front(b, -2);
     push_front(b, -6);
     push_front(b, -3);
     push_front(b, -4);
     push_front(b, -5);

     Node* c = NULL;
     push_front(c, 18);
     push_front(c, 1);
     push_front(c, 2);
     push_front(c, 6);
     push_front(c, 3);
     push_front(c, 4);
     push_front(c, 5);

     int k;
     int i;
     //cin>>k;

cout<<" a :";
print(head);
cout<<" b :";
print(b);
cout<<" c :";
print(c);
    Node *t1,*t2,*t3;
if(find_zero_sum(head,b,c,t1,t2,t3))
    cout<<" Found : "<<t1->data<<" + "<<t2->data<<" + "<<t3->data<<" = 0 "<<endl;
else
    cout<<" Not Found "<<endl;


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
