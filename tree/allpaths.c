#include<stdio.h>
int path[1000];
typedef struct node 
{
struct node *left;
int data;
struct node* right;
}Node;

int cntleaves(Node* root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	return cntleaves(root->left)+cntleaves(root->right);

}



void printArray(int path[],int len)
{
	int i=0;
for(i=0;i<len;i++)
	printf(" %d ",path[i]);
printf("\n");
}
void printPaths(Node* root,int len)
{
	if(root==NULL)
		return;
	path[len++]=root->data;
	if(root->left==NULL && root->right==NULL)
	{	printArray(path,len);
		return;
	}
	printPaths(root->left,len);
	printPaths(root->right,len);
}
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

void printNodewithLeafChildren(Node *root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
		return;
	if(	root->left && root->right )
	{
		if((root->right->left==NULL && root->right->right==NULL) ||  (root->left->left==NULL && root->left->right==NULL ))
			printf("	%d",root->data);
		//else
		{
			printNodewithLeafChildren(root->left);
			printNodewithLeafChildren(root->right);
		}
	
	}
	else if(root->left)
	{
		if(root->left->left==NULL && root->left->right==NULL)
			printf("	%d",root->data);
		//else
			printNodewithLeafChildren(root->left);
			
	
	}
	else if(root->right)
	{
		if(root->right->left==NULL && root->right->right==NULL)
			printf("	%d",root->data);
		//else
			printNodewithLeafChildren(root->right);
	}
		
}
int main()
{
/* Constructed binary tree is
            10
          /   \
        8      32
      /  \    / \
    3     5  2	 12	
		 / \
	    22  21
*/
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
  root->right->right = newnode(12);
  root->left->right->left = newnode(22);
  root->left->right->right = newnode(21);
  
printPaths(root,0);

printf("\nThe total no. of leaves in the tree are  %d\n\n\t",cntleaves(root));

printNodewithLeafChildren(root);
return 0;
}