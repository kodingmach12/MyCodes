#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node
{
int data;
struct node *left;
struct node *right;
}Node;

Node* newNode(int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
return(node);
}

//Lowest Common Ancestor of a Binary Tree
int covers(Node *root,int p)
{
	if(root==NULL)
		return 0;
	if(root->data==p)
		return 1;
	return covers(root->left,p) || covers(root->right,p);
}

Node* findCommomAncestor(Node *root,int p,int q)
{
	if( covers(root->left,p) && covers(root->left,q) )
		return findCommomAncestor(root->left,p,q);
	if( covers(root->right,p) && covers(root->right,q) )
		return findCommomAncestor(root->right,p,q);
	return root;
}
void inorder(Node *p)
{
    if(!p)  return;
    inorder(p->left);
    cout<<" "<<p->data;
    inorder(p->right);
}
int main()
{
  int minsum=0;
  Node *root = newNode(11);
  root->left        = newNode(2);
  root->right       = newNode(31);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(6);
  root->left->left->right  = newNode(16);
  int a,b;
  inorder(root);
  cout<<endl;
  cin>>a>>b;
  Node *lca= findCommomAncestor(root,a,b);
  cout<<" Lca Node is "<<lca->data<<endl;
return 0;
}

