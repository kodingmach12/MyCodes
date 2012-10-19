#include<stdio.h>
#include<malloc.h>
                    //recursive implementation of level order traversal

typedef struct node
{
struct node *left;
struct node *right;
    int data;
}Node;

int max(int a,int b)
{
 return (a>b?a:b);
}

int  height(Node *root)
{
    if(root==NULL)
        return 0;
    int ht=0;
  return (1+max(height(root->left),height(root->right)));
}

void printGivenLevel(Node *root,int level)
{
    if(root==NULL)
        return;
    if(level==0)
        printf("    %d",root->data);
    else
    {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}
void printLevelOrder(Node *root)
{
if(root==NULL)
    return;
int ht=height(root);
//printf("\nthe height of given tree is %d\n",ht);

int i=0;
    for(i=0;i<=ht;i++)
    {
    printGivenLevel(root,i);
    printf("\n");
    }
}
Node* newNode(int n)
{
    Node *temp=(Node*)malloc(sizeof(Node));
if(temp!=NULL)
{
     temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
}
return temp;
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(6);
    printLevelOrder(root);

return 0;
}
