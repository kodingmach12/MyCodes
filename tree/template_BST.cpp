#include<iostream>
#include<cstdio>
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
bool printpath(Node* root, int k)
{
    if(!root)   return (k?false:true);      // return false if k is non-zero and root is null and true if k is zero
    if(root->data==k){
        cout<<" "<<root->data;
        return true;
    }
    if(printpath(root->left,k-root->data) || printpath(root->right,k-root->data))
    {
        printf(" %d ",root->data);
        return true;
    }
    return false;
}

int main()
{
/*          4
        2       3
    1       3       8
*/



  Node *root        = newNode(8);

  root->left        = newNode(4);
  root->left->left  = newNode(2);
  root->left->left->left    = newNode(1);
  root->left->left->right   = newNode(3);
  root->left->right = newNode(6);
  root->left->right->left   = newNode(5);
  root->left->right->right  = newNode(7);

  root->right        = newNode(12);
  root->right->left  = newNode(10);
  root->right->left->left    = newNode(9);
  root->right->left->right   = newNode(11);
  root->right->right = newNode(14);
  root->right->right->left   = newNode(13);
  root->right->right->right  = newNode(15);


inorder(root);
cout<<endl;
    int n;
    cin>>n;
    if(printpath(root,n))
        printf("Sum found\n");
    else
        printf("Sum Not found\n");

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
