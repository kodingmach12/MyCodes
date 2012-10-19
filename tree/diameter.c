#include<stdio.h>
struct node 
{
int data;
struct node *left;
struct node *right;
};
//typedef struct node * Node*;
int max(int a,int b)
{
return (a>b?a:b);
}

int height(struct node * root)
{
if(root==NULL)
	return 0;
return 1+max(height(root->left),height(root->right));
}
int diameter(struct node *root)
{
if(root==NULL)
	return 0;
int lh=height(root->left);
int rh=height(root->right);

int ld=diameter(root->left);
int rd=diameter(root->right);

return  max(1+lh+rh,max(ld,rd));
}

int minSum=0;
void findMinSum(struct node *root, int sum) 
{
   if(root == NULL)
       printf("Tree doesn't have any data\n");

   if (root->left == NULL && root->right == NULL) 
   {
       if (minSum > sum + root->data) 
	   {
			printf("   %d->",root->data);
            minSum = (sum + root->data);
       }
       return;
   }
   if(root->left) 
   {
           findMinSum(root->left, sum + root->data);
   }
   if(root->right) 
   {
           findMinSum(root->right, sum + root->data);
   }
}
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}


int main()
{
  int minsum=0;
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(6);
  printf("Diameter of the given binary tree is %d\n", diameter(root));
 
 //findminsum(root,0);
 printf("\nThe min sum is %d\n",minsum);
  getchar();
  return 0;
}

