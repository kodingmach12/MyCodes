#include<stdio.h>
typedef struct node
{
	struct node* left;
	int data;
	struct node*right;
}Node;
bool isleaf(Node *p)
{
    return (!p->left && !p->right);
}
//Subtree with maximum sum
Node *maxSumSubtree(Node *root)
{
    if(!root)   return NULL;
    if(isleaf(root))    return root;
    int maxsum=0;
    Node *res=NULL;
    helper(root,&res,&maxsum);
return *res;
}
int helper(Node *p,Node **res,int *maxSum)
{
    if(!p)  return 0;
    int lsum  = helper(p->left,res,maxsum);
    int rsum  = helper(p->right,res,maxsum);
    int total = lsum + rsum + p->data;
    if( total > *maxsum ){
        *maxsum=total;
        *res=p;
    }
return total;
}
int maxSum(struct node* root, int* max)
{
    if(root == NULL)
        return 0;
    int sum = maxSum(root->left, max) + maxSum(root->right, max) + root->data;
    if(sum > *max)
        *max = sum;
    return sum;
}
struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
   return(node);
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(-10);
  root->right       = newNode(-30);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(-6);


    int max=0;

    maxSum(root, &max);
    printf("maxSum = %d\n", max);

    return 0;
}
