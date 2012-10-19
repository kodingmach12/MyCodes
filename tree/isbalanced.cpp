#include<iostream>
#include<algorithm>
#define TRUE 1
#define FALSE 0
using namespace std;
typedef struct node
{
struct node *left;
int data;
struct node *right;
}Node;
bool is_balanced_opt(Node *t, int &minht, int &maxht, bool &res)
{
    if(res)
    {
        if(!t)  return true;
        int lmin,lmax,rmin,rmax;

        bool left  = is_balanced_opt(root->left, lmin, lmax, res);
        if(left==false)
        {
            res=false;
            return false;
        }

        bool right = is_balanced_opt(root->right, rmin, rmax, res);
        if(left && right)
        {
            minht = min(lmin,lmax);
            maxht = max(lmax,rmax);
            return true;
        }
        else
        {
            res=false;
            return false;
        }
    }
return false;
}

int min(int a, int b)
{
    return (a<b)?a:b;

}
int max(int a, int b)
{
    return (a>b)?a:b;

}

void min_max_height(Node *tree, int &min_h, int &max_h )
{
        if(!tree)
        {
            min_h=0;
            max_h=0;
            return;
        }
        int lmin=0,lmax=0,rmin=0,rmax=0;
        min_max_height(tree->left,lmin,lmax);
        min_max_height(tree->right,rmin,rmax);
        min_h=min(lmin,rmin);
        max_h=max(lmax,rmax);

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
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
    int min_h,max_h;
    min_max_height(root,min_h,max_h);
    cout<<" min height is "<<min_h<<" max height is "<<max_h<<endl;


  return 0;
}
