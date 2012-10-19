#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef struct node
{
    int data;
    struct node  *left;
    struct node  *right;
}Node;
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
Node* newNode(int );

int findYinXZpath(Node  *root,Node *x,Node *y,Node *z,int yfound,int xfound)
{
    //Assuming only X to Z path and not the vice-versa
    //Considering only downWards path
    if(!root)   return 0;
    if(root==x) xfound=1;
    else if(root==z) return yfound;
    else if(root==y)  {
        if(xfound)
          yfound=1;
        else
            return 0;
    }
    if(findYinXZpath(root->left,x,y,z,yfound,xfound))  return 1;

    return findYinXZpath(root->right,x,y,z,yfound,xfound);
}




int main()
{

  Node *root        = newNode(1);

  root->left        = newNode(2);
  root->left->left  = newNode(4);
  root->left->left->left    = newNode(4);
  root->left->left->right   = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left   = newNode(5);
  root->left->right->right  = newNode(5);

  root->right       = newNode(3);
  root->right->left  = newNode(4);
  root->right->left->left    = newNode(4);
  root->right->left->right   = newNode(4);
  root->right->right = newNode(5);
  root->right->right->left   = newNode(5);
  root->right->right->right  = newNode(5);


inorder(root);

return 0;
}

Node* newNode(int val)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp)
    {
        temp->data=val;
        temp->left=temp->right=NULL;
    }
    else
        cout<<" Memory Error"<<endl;
return temp;
}
void inorder(Node *root)
{
    if(!root)   return;
    inorder(root->left);
    cout<<" "<<root->data;
    inorder(root->right);
}
void preorder(Node *root)
{
    if(!root)   return;
    cout<<" "<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if(!root)   return;
    postorder(root->left);
    postorder(root->right);
    cout<<" "<<root->data;
}

