#include<stdio.h>
#define bool int
#define true 1
#define false 0
typedef struct stack
{
	BinaryTree *info;
	struct stack *next;
}stack;
typedef struct BinaryTree
{
    struct BinaryTree *left;
    int data;
    struct BinaryTree *right;
}BinaryTree;
void printLevelOrderZigZag(BinaryTree *root)
{
  stack<BinaryTree*> currentLevel, nextLevel;
    bool leftToRight = true;
  currentLevel.push(root);
  while(!currentLevel.empty())
  {
    BinaryTree *currNode = currentLevel.top();
    currentLevel.pop();
    if (currNode)
    {
      cout << currNode->data << " ";
      if (leftToRight)
      {
        nextLevel.push(currNode->left);
        nextLevel.push(currNode->right);
      }
      else
      {
        nextLevel.push(currNode->right);
        nextLevel.push(currNode->left);
      }
    }
    if(currentLevel.empty())
    {
      cout << endl;
      leftToRight = !leftToRight;
      swap(currentLevel, nextLevel);
    }
  }
}
