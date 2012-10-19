#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<climits>
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

// Find the largest BST in a binary tree.
// This code does not delete dynamically-allocated nodes,
// so memory will be leaked upon exit.
// The min and max values are passed top-down to check if
// including a node satisfies the current BST constraint.
// The child nodes are passed bottom-up to be assigned
// to its parent.
// Returns the total number of nodes the child holds.
int findLargestBST(BinaryTree *p, int min, int max, int &maxNodes,
                   BinaryTree *& largestBST, BinaryTree *& child)
{
  if (!p) return 0;
  if (min < p->data && p->data < max)
  {
    int leftNodes = findLargestBST(p->left, min, p->data, maxNodes, largestBST, child);
    BinaryTree *leftChild = (leftNodes == 0) ? NULL : child;

    int rightNodes = findLargestBST(p->right, p->data, max, maxNodes, largestBST, child);
    BinaryTree *rightChild = (rightNodes == 0) ? NULL : child;

    // create a copy of the current node and
    // assign its left and right child.

    BinaryTree *parent = new BinaryTree(p->data);
    parent->left = leftChild;
    parent->right = rightChild;
    // pass the parent as the child to the above tree.
    child = parent;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      maxNodes = totalNodes;
      largestBST = parent;
    }
    return totalNodes;
  } else {
    // include this node breaks the BST constraint,
    // so treat this node as an entirely new tree and
    // check if a larger BST exist in this tree
    findLargestBST(p, INT_MIN, INT_MAX, maxNodes, largestBST, child);
    // must return 0 to exclude this node
    return 0;
  }
}

BinaryTree* findLargestBST(BinaryTree *root) {
  BinaryTree *largestBST = NULL;
  BinaryTree *child;
  int maxNodes = INT_MIN;
  findLargestBST(root, INT_MIN, INT_MAX, maxNodes, largestBST, child);
  return largestBST;
}


int main()
{
/*              8
        4                  12
    2       6         10       15
   1  3   51   7     9    11  14    9
*/

  Node *root        = newNode(8);

  root->left        = newNode(4);
  root->left->left  = newNode(2);
  root->left->left->left    = newNode(1);
  root->left->left->right   = newNode(3);
  root->left->right = newNode(6);
  root->left->right->left   = newNode(51);
  root->left->right->right  = newNode(7);

  root->right       = newNode(12);
  root->right->left  = newNode(10);
  root->right->left->left    = newNode(9);
  root->right->left->right   = newNode(11);
  root->right->right = newNode(15);
  root->right->right->left   = newNode(14);
  root->right->right->right  = newNode(9);

  cout<<" inorder (root) :";
  inorder(root);
  cout<<endl;

  Node *largest=NULL;
  int tnodes=0;

  findLargestBSTsubtree(root,largest,tnodes);

  cout<<" Largest BST contains "<<tnodes<<" nodes"<<endl<<" inorder (Largest) :";
  inorder(largest);
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
