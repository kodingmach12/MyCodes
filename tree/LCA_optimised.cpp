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
int covers(Node *root, int p, int q)
{
    int nodes_found=0;
	if(root==NULL)  return nodes_found;
	if(root->data == p || root->data == q)
        nodes_found++;
    nodes_found+= covers(root->left,p,q);
    if(nodes_found==2)
        return nodes_found;
    return nodes_found + covers(root->right,p,q);
}

Node* findCommomAncestor(Node *root,int p,int q)
{
    if(!root)   return NULL;
    if( (q == p)  && (root->left==p || root->right==p) )
        return root;
    int nodes_from_left = covers(root->left,p,q);
        if(nodes_from_left==2)
        {
            if( (root->left == p) || (root->left == q) )
                return root->left;
            return findCommomAncestor(root->left,p,q);
        }
        else if(nodes_from_left == 1)
        {
            if(root == p) return q;
            if(root == q) return p;
        }

    int nodes_from_right = covers(root->right,p,q);
        if(nodes_from_right == 2)
        {
            if( root->right==p || root->right==q )
                return root->right;
            return findCommomAncestor(root->right,p,q);
        }
        else if(nodes_from_right==1)
        {
                if(root==p || root==q)
                    return root;
        }
    if(nodes_from_left==nodes_from_right && nodes_from_left==1)
        return root;
return NULL;
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

