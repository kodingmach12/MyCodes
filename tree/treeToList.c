#include<stdio.h>
typedef struct List
{
	struct List *prev;
	int data;
	struct List* next;
}List;
typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
}Node;

List* newListNode(int n)
{
    List* temp=(List*)malloc(sizeof(List));
    temp->data=n;
    temp->next=NULL;
    temp->prev=NULL;

return temp;
}
List* append(List *a,List *b)
{
    if(a==NULL)   return b;
    if(b==NULL)   return a;

    List *temp=a;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=b;
    b->prev=temp;
    b->next=NULL;

return a;
}

List* treeToList(Node* root)
{
    if(root==NULL)
        return NULL;
    List *left=NULL,*right=NULL;
//printf("in");
    left=treeToList(root->left);
    right=treeToList(root->right);

    List *rt=newListNode(root->data);
     rt->next=rt;
     rt->prev=rt;

    left=append(left,rt);
    left=append(left,right);

return left;
}

Node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
void inorder(Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("    %d",root->data);
    inorder(root->right);
}

int main()
{
/*
        4
    2       6
  1    3        8
*/
    Node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(6);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
  root->right->right  = newNode(8);
  printf("The inorder tree traversal is \n");
  inorder(root);

List *head=treeToList(root);


while(head->next!=NULL);
{
    printf("  %d",head->data);
    head=head->next;
}

return 0;
}
