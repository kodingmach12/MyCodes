#include<stdio.h>
typedef	struct node 
	{
		int data;
		struct node *left;
		struct node *right;
	}Node;
int klargest(Node *root,int k)
{
	if(root==NULL || k==0)
	{
		printf("Element Not Found");
	 return -1;
	}
	int rcount=count(root->right);
	if(rcount==k-1)
		return root->data;
	if(rcount>=k)
		return klargest(root->right,k);
	else
		return klargest(root->left,k-1-rcount);
}

int ksmallest(struct node *root,int k)
{
	if(root==NULL || k==0)
	{
		printf("\nElement Not Found");
		return -1;
	}
	int leftnum=count(root->left);
//	printf("\n Leftnum : %d  --",leftnum);
	if(leftnum==(k-1))
	{	return root->data;
	}
	if(leftnum<k-1)
	   return ksmallest(root->right,k-1-leftnum);
	if(leftnum>=k)
	   return ksmallest(root->left,k);
	
	}

struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
int count(Node *root)
{
	if(root==NULL)
		return 0;
	return 1+count(root->left)+count(root->right);
}
int rcount(Node *root)
{
	if(root==NULL)
		return 0;
	return 1+rcount(root->left)+rcount(root->right);
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
  int k;
  struct node *root = newNode(8);
  root->left        = newNode(6);
  root->right       = newNode(12);
  root->left->left  = newNode(4);
  root->left->right = newNode(7);
  root->left->left->left  = newNode(2);
  inorder(root);
  //printf("\nEnter the number --    ");
  //scanf("%d",&k);
  int i;
	//scanf("%d",&k);
	for(i=0;i<8;i++)
	   printf("\nThe %d smallest element of BST is %d ",i,ksmallest(root,i));
	for(i=0;i<8;i++)
	   printf("\nThe %d smallest element of BST is %d ",i,klargest(root,i));
	
}
