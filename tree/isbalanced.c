#include<iostream>
#define TRUE 1
#define FALSE 0
using namespace std;
typedef struct node
{
struct node *left;
int data;
struct node *right;
}Node;

void min_max_height(Node *tree, int &min, int &max )
{
        if(!tree)
        {
            min=0;
            max=0;
            return;
        }
        int lmin=0,lmax=0,rmin=0,rmax=0;
        min_max_height(tree->left,lmin,lmax);
        min_max_height(tree->right,rmin,rmax);
        min=min(lmin,rmin);
        max=max(lmax,rmax);

}
int minheight(Node *tree)
{
if(tree==NULL)
	return 0;
return 1+min(minheight(tree->left),minheight(tree->right));
}

int maxheight(Node *tree)
{
if(tree==NULL)
	return 0;
return 1+max(maxheight(tree->left),maxheight(tree->right));
}


int isbalanced(Node *tree)
{
    if(tree==NULL)        return TRUE;
    int minht=minheight(tree);
    int maxht=maxheight(tree);
    if(maxheight-minheight>1)
        return FALSE;
    else
        return isbalanced(tree->left)&&isbalanced(tree->right);
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
    int min,max;
    min_max_height(root,min,max);
    cout<<" min height is "<<min<<" max height is "<<max<<endl;


  return 0;
}
