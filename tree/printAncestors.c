#include<stdio.h>
#include<limits.h>
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
    if(root==NULL )
        return 0;
    if(root->data == k)
        return 0;

    if( (root->left->data==k) || (root->right->data==k) ||
         findancestor(root->left,k) || findancestor(root->right,k))
    {
        printf(" %d ",root->data);
        return 1;
    }
return 0;
}
void doubleTree(Node *root)
{
    if(root==NULL)
        return;
        Node *old_left;
    doubleTree(root->left);
    doubleTree(root->right);
    old_left=root->left;
    root->left=newNode(root->data);
    root->left->left=old_left;

}
int is_symmetric(Node *a,Node *b)
{
    if(a==NULL)
        return (b==NULL);
    if(b==NULL)
        return 0;
    if(!a->left && b->left)
        return 0;
    if(!a->right && b->right)
        return 0;

return  (is_symmetric(a->left,b->left) && is_symmetric(a->right,b->right) );

}
int main()
{
/*                12
        4               4
    1       3       1       3
        2               2
*/
  int a=8;
  Node *root = newNode(12);
  root->left        = newNode(4);
  root->right       = newNode(4);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
  root->right->left = newNode(1);
  root->right->right = newNode(3);
  root->left->left->right  = newNode(2);
  root->right->left->right  = newNode(2);
  inorder(root);
  //doubleTree(root);
  printf("\n");
  if(is_symmetric(root->left,root->right))
    printf("Symmetric");
  else
    printf("Not Symmetric");
  //inorder(root);
  //scanf("%d",&a);
//  if(findancestor(root,a)==0)
  //  printf("\nNode not found,No Ancestors");
//  printf("\nThe max val is %d",maxval(root));
return 0;
}

