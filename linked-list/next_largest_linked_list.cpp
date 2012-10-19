#include<iostream>
#include<stack>
#include<algorithm>
#include<cstdlib>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *next_largest;
}Node;

void push_at_front( Node *&, int );
void printList(Node*);
void push_at_end(Node *&,int);
Node* newNode(int);

Node* fill_next_largest(Node *head)
{
    if(!head  )   return NULL;
    if(!head->next )    return head;

    stack<Node*> s;
    Node *tmp=NULL,*cur=head,*next=NULL,*min_node=NULL;
    min_node=cur;
    s.push(cur);
    cur=cur->next;
    while(cur)
    {
        if(cur->data < min_node->data)
            min_node=cur;
      next=cur;
      while(!s.empty() && (s.top())->data < next->data)
      {
          tmp=s.top();
          tmp->next_largest=next;
          s.pop();
      }
      s.push(next);
      cur=cur->next;
    }
    while(!s.empty())
    {
     tmp=s.top();
     tmp->next_largest=NULL;
     s.pop();
    }
return min_node;
}

int main()
{
     struct node* head = NULL;
     push_at_front(head, 1);
     push_at_front(head, 2);
     push_at_front(head, 8);
     push_at_front(head, 4);
     push_at_front(head, 11);
     push_at_front(head, 6);
     push_at_front(head, 7);
     push_at_end(head,9);
     int k;
     int i;
     //cin>>k;
        printList(head);
        fill_next_largest(head);
        printList(head);
return 0;
}
void push_at_front( Node *&head_ref, int val)
{
    Node* new_node = newNode(val);
    if(head_ref==NULL)
      head_ref    = new_node;
    else
    {
        new_node->next=head_ref;
        head_ref=new_node;
    }
}

Node* newNode(int val)
{
    Node *temp=(Node*)malloc(sizeof(Node));
          temp->data=val;
          temp->next=NULL;
          temp->next_largest=NULL;
return temp;
}
void push_at_end(Node *&head_ref,int data)
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
void printList(Node *head)
{
    if(head)
    {
        while(head)
        {
            cout<<" "<<head->data;
            if(head->next_largest)
                cout<<" next largest is  "<<head->next_largest->data<<endl;
            else
                cout<<" No next largest element found "<<endl;
            head=head->next;
       }
        cout<<endl;
    }
}

