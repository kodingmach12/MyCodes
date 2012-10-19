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

// Find the largest BST subtree in a binary tree.
// If the subtree is a BST, return total number of nodes.
// If the subtree is not a BST, -1 is returned.

int helper(Node *p, int &min, int &max,int &maxNodes, Node *& largestBST)
{
  if (!p) return 0;
  bool isBST = true;

  int leftNodes = helper(p->left, min, max, maxNodes, largestBST);
  int currMin = (leftNodes == 0) ? p->data : min;
  if (leftNodes == -1 ||
     (leftNodes != 0 && p->data <= max))
    isBST = false;

  int rightNodes = helper(p->right, min, max, maxNodes, largestBST);
  int currMax = (rightNodes == 0) ? p->data : max;
  if (rightNodes == -1 ||
     (rightNodes != 0 && p->data >= min))
    isBST = false;

  if (isBST)
  {
    min = currMin;
    max = currMax;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes)
    {
      maxNodes = totalNodes;
      largestBST = p;
    }
    return totalNodes;
  }
  else
     return -1;   // This subtree is not a BST
}

Node* findLargestBSTsubtree(Node *root)
{
  Node *largestBST = NULL;
  int min=INT_MAX, max=INT_MIN,maxNodes =0;
  helper(root, &min, &max, &maxNodes, &largestBST);
  return largestBST;
}


int main()
{
/*              8
        4                  12
    2       5         10       15
   1  3   6   7     9    11  14    9
*/

  Node *root        = newNode(8);

  root->left        = newNode(4);
  root->left->left  = newNode(2);
  root->left->left->left    = newNode(1);
  root->left->left->right   = newNode(3);
  root->left->right = newNode(6);
  root->left->right->left   = newNode(5);
  root->left->right->right  = newNode(7);

  root->right       = newNode(12);
  root->right->left  = newNode(10);
  root->right->left->left    = newNode(9);
  root->right->left->right   = newNode(11);
  root->right->right = newNode(15);
  root->right->right->left   = newNode(14);
  root->right->right->right  = newNode(9);


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



