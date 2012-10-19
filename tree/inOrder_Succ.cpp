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

// return values
//  0 - success
//  1- node found, successor not found
//  2- node not found
// Worst case time complexity - > O(n)

int inOrder_Succ(Node *root,Node *p,Node **succ)
{
    if(!root)   return 2;
    Node *temp=NULL;
    if(root==p)
    {
        if(root->right)
        {   temp=root->right;
            while(temp->left)
                temp=temp->left;
            *succ=temp;
            return 0;
        }
        return 1;
    }
    int retval=0;
    if(root->left)
    {
        retval=inOrder_Succ(root->left,p,succ);
        if(retval==0)
            return 0;
        if(retval==1)
        {
            *succ=root;
            return 0;
        }
    }
    if(root->right)
    {
            return inOrder_Succ(root->right,p,succ);
    }
return 2;
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
    Node *temp=newNode(123);
  root->right       =   temp;            //newNode(3);
  root->right->left  = newNode(4);
  root->right->left->left    = newNode(4);
  root->right->left->right   = newNode(4);
  root->right->right = newNode(5);
  root->right->right->left   = newNode(5);
  root->right->right->right  = newNode(5);

Node* succ=NULL;
inorder(root);
inOrder_Succ(root,temp,&succ);
cout<<" The inorder successor of "<<temp->data<<" is "<<succ->data<<endl;

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
