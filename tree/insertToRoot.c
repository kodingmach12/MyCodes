#include<stdio.h>
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

Node* insertToRoot(Node *root,Node *p)
{
    if(root==NULL)
        return p;
    Node *newroot=p,*parent=NULL;
    if(root->data >= p->data)
    {
    newroot->right=root;
        if(!root->left)
            return newroot;
        parent=root;
        root=root->left;
    while(root->data > newroot->data && root->left!=NULL)
     {
            parent=root;
           root=root->left;
     }
     if(root->data>=newroot->data)
            newroot->left=NULL;
     else
     {
      newroot->left=root;
      parent->left=NULL;
     }
    }
    else
    {
        newroot->left=root;
            if(!root->right)
                return newroot;
            parent=root;
            root=root->right;
        while((root->data < newroot->data)&&(root->right!=NULL))
        {
            parent=root;
            root=root->right;
        }
        if(root->data<newroot->data)
            newroot->right=NULL;
        else
        {
        newroot->right=root;
        parent->right=NULL;
        }
    }
return newroot;
}
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);

}

int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(6);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);
  root->right->right  = newNode(8);
  inorder(root);

printf("\nthe new tree is\n");
struct node *p=newNode(0);
struct node *newtree=NULL;
newtree=insertToRoot(root,p);

inorder(newtree);
return 0;
}
