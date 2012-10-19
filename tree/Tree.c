#include<stdio.h>
#include<malloc.h>
#include<limits.h>
#define bool int
#define true 1
#define false 0

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}Node;
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);

}
int  findancestor(Node *root,int k)
{
    if(!root || root->data == k)
        return 0;

    if(root->left->data==k || root->right->data==k ||
        findancestor(root->left,k) || findancestor(root->right,k))
    {
        printf(" %d ",root->data);
        return 1;
    }
    else
        printf("\nNode Not Found");
}
void preordermorrisiterative(Node *root)
{
    Node *current = root, *pred = NULL, *succesor = NULL;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            printf(" %d ", current->data);
            current = current->right;
        }
        else
        {
            pred = current->left;
            while (pred->right != NULL && pred->right != current)
             {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                pred->right = current;
                //preorder
                printf(" %d ", current->data);
                current = current->left;
            } else {
                pred->right = NULL;
                //inorder   //printf(" %d ", current->data);
                current = current->right;
            }
        }
    }
}
void inorderMorrisIterative(Node *root)
{
    if(root==NULL)
        return;
    Node *current=root,*pre=NULL;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            printf("%d ",current->data);
            current=current->right;
        }
        else
        {
            pre=current->left;
            while(pre->right!=NULL && pre->right!=current)
                pre=pre->right;
            if(pre->right==NULL)
            {
                pre->right=current;
                current=current->left;
            }
            else
            {
                pre->right=NULL;
                printf("%d ",current->data);
                current=current->right;
            }
        }
    }
}
void postorderMorrisIterative(Node *root)
{
    if(!root)
        return;

}
int max(int a,int b)
{
    return (a>b)?a:b;
}
int maxval(Node  *root)
{
    if(!root)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
         int lsum=0,rsum=0;           //Use Post order traversal
         if(root->left)
            lsum=maxval(root->left);
        if(root->right)
            rsum=maxval(root->right);
        int rootsum=root->data+lsum+rsum;
// printf("\n  %d  %d  %d",lsum,rsum,rootsum);
return max(max(lsum,rsum),rootsum);
}
int sumtree(Node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    int lsum=0,rsum=0,temp=root->data;
    if(root->left)
        lsum=sumtree(root->left);
    if(root->right)
        rsum=sumtree(root->right);
    root->data=lsum+rsum;

//return temp+lsum+rsum;
return root->data;
}
int balanceup(Node *root)
{
if(root==NULL)
	return 0;
if(root->left==NULL  && root->right==NULL)
	return root->data;
int left=0,right=0;
if(root->left)
  left=balanceup(root->left);
if(root->right)
   right=balanceup(root->right);
if(root->data < left+right )
	root->data=left+right;
  return root->data;
}
void balancedown(Node *root)
{
if(root==NULL)
	return 0;
if(root->left==NULL  && root->right==NULL)
	return root->data;
Node *min=NULL;
if(root->data > left+right )
	root->data=left+right;

if(root->left)
  left=balanceup(root->left);
if(root->right)
   right=balanceup(root->right);
  return root->data;

}
void Preorder(Node *root)
{
if(root==NULL)
	return;
Node *current=root;
Stack *s=CreateStack();
while(1)
{
	 while(current)
 	{
	printf("%d ",current->data);
	s.push(current);
	current=current->left;
	}
	if(IsEmpty(s))
		break;

	current=s.pop();
	current=current->right;

}
DeleteStack(s);
}
bool isEqual(Node *a,Node *b)
{
if(a==NULL && b==NULL)
	return true;
if(a==NULL || b==NULL)
	return false;
if(a->data==b->data && isEqual(a->left,b->left) && isEqual(a->right,b->right) )
	return true;
return false;
}


// A function that fills count array with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(struct node *root, int count[], int level);

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(struct node* root)
{
  int width;
  int h = height(root);

  // Create an array that will store count of nodes at each level
  int *count = (int *)calloc(sizeof(int), h);

  int level = 0;

  // Fill the count array using preorder traversal
  getMaxWidthRecur(root, count, level);

  // Return the maximum value from count array
  return getMax(count, h);
}

// A function that fills count array with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(struct node *root, int count[], int level)
{
  if(root)
  {
    count[level]++;
    getMaxWidthRecur(root->left, count, level+1);
    getMaxWidthRecur(root->right, count, level+1);
  }
}
int main()
{
/*                12
        4               14
    1       13       10		7

*/
  Node *root = newNode(123);
  root->left        = newNode(4);
  root->right       = newNode(14);
  root->left->left  = newNode(1);
  root->left->right = newNode(13);
  root->right->left = newNode(10);
  root->right->right  = newNode(7);
  //inorderMorrisIterative(root);
//    MorrisTraversal2(root);
//  printf("\nThe preorder traveral is --\t");
 // preordermorrisiterative(root);
 // printf("\nThe inorder traveral is --\t");
  inorderMorrisIterative(root);
balanceup(root);
//    sumtree(root);
    printf("\n");
  inorderMorrisIterative(root);
  printf("\n");
   int a=8;
   // scanf("%d",&a);
  //findancestor(root,a);
//  printf("\nThe max val is %d",maxval(root));
return 0;
}
