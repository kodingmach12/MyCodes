#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;
Node* append(Node *a, Node* b)
{
    if(!a)  return b;
    if(!b)  return a;
    Node *alast=a->left;
    Node *blast=b->left;

    alast->right=b;
    b->left=alast;

    a->left=NULL;
    blast->right=NULL;

return a;
}

Node* Tree2List(Node *t1)
{
    if(!t1)     return NULL;
    Node* aList=Tree2List(t1->left);
    Node* bList=Tree2List(t1->right);
    root->left=root;
    root->right=root;
    aList=append(aList,root);
    bList=append(aList,bList);
// To convert from dll to sll -> code starts here
    Node *prev=aList->left;
    aList->left=NULL;
    prev->right=NULL;
//  Code ends here
return aList;
}

Node* mergeList(Node* l1, Node* l2)
{
    Node *atmp=l1,*btmp=l2;
    Node *final=newNode(123),*res=final;
    while( atmp && btmp)
    {
        if(atmp->data < btmp->data)
        {
            res->next=atmp;
            atmp=atmp->next;
        }
        else
        {
            res->next=btmp;
            btmp=btmp->next;
        }
        res=res->next;
   }
   if(atmp || btmp)
   {
       Node *tmp=(atmp)? atmp : btmp;
       while(tmp)
       {
           res->next=tmp;
           tmp=tmp->next;
           res=res->next;
       }
   }
   res->next=NULL;
tmp=final;
final=final->next;
free(tmp);
return final;
}

int count(Node* head)
{
    int cnt=0;
    while(head)
    {
        cnt++;
        head=head->next;
    }
return cnt;
}
Node* makeTreehelper(Node *&list, int n)
{
    if(n==0)    return NULL;
    if(n==1)
    {
        list->left=NULL;
        list->right=NULL;
        return List;
    }
    Node* left=makeTreehelper(list,n/2);
    Node* root=list;
    root->left=left;
    list = list->next;
    root->right=makeTreehelper(list,n-n/2-1);
return root;
}
Node* makeTree4mList(Node *List)
{
    int n=count(List);
    return makeTreehelper(List,n);
}

Node* mergeBST(Node *t1,Node *t2)
{
    if(!t1 && !t2)  return NULL;
    Node *t=NULL;
    if(!t1) return t2;
    if(!t2) return t1;
    t1=Tree2List(t1);
    t2=Tree2List(t2);
    t=MergeList(t1,t2);

    t=MakeTree4mList(t);
return t;
}
