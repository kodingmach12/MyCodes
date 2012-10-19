#include<stdio.h>
#include<malloc.h>
typedef struct Dnode
{
    int data;
    struct node* next;
    struct node* prev;
}Dnode;
Dnode* createNode(int t)
{
    Dnode* temp=(Dnode*)malloc(sizeof(Dnode));
    temp->data=t;
    temp->next=temp->prev=NULL;
return temp;
}
Dnode* createList(int n)
{   int i=0,a=0;
    Dnode* pre=NULL;
    for(i=0;i<n;i++)
    {
        Dnode* temp=createNode(a);
        temp->prev=pre;
        if(temp->prev)
            temp->prev->next=temp;
    }
}
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;
int left(Node *root)
{
    int l=0;
    while(root->left!=NULL)
    {	root=root->left;
	l++;
    }
    return l;
}
void fillarray(Dnode* vsum,int size,int cur_pos,Node *root)
{
    int i;
    if(root==NULL)  return;
    if(root->left)
    {
	  vsum->prev->data += root->left->data;
	fillarray(vsum->prev,size,cur_pos-1,root->left);
    }
    if(root->right)
    {
	  vsum->next->data +=root->right->data;
	fillarray(vsum->next,size,cur_pos+1,root->right);
    }
}
void verticalsum(Node *root)
{
	if(root==NULL)
		return;
    Node *p=root;
    int i=0,size=0,cnt=0;
	while(p->left!=NULL)
	{
		cnt++;
		p=p->left;
	}
    p=root;
	while(p->right!=NULL)
	{
		cnt++;
		p=p->right;
	}
    size=cnt+1; //this is the size of array to be allocated for storing the vertical sum
    Dnode* vsum= createList(size);
    int leftelem = left(root);
	Node* temp=vsum;
	int i=0;
	while(i<leftelem)
        temp=temp->next;
    temp->data=root->data;
    fillarray(temp,size,leftelem,root);
}
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
 if(node)
 {

  node->data = data;
  node->left = NULL;
  node->right = NULL;

 }
  return(node);
}
void inorder(Node *root)
{
if(root==NULL)
	return;
inorder(root->left);
	printf("	%d",root->data);
inorder(root->right);

}

int main()
{
  Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(6);
  root->right->left=newNode(6);
  root->right->right=newNode(7);
  root->right->right->left=newNode(7);

inorder(root);
printf("\n");
verticalsum(root);
return 0;
}
