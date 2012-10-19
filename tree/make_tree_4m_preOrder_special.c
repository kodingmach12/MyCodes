#include <iostream>
using namespace std;
typedef struct node{
int  data;
struct node *left,*right;
}tree;
void inorder(tree *p)
{
    if(!p)  return;
    inorder(p->left);
    cout<<" "<<p->data<<" ";
    inorder(p->right);
}
tree* newnode(char c)
{
    tree *node = new(tree);
    node->val = c;
    node->left = node->right = NULL;
    return node;
}

tree* construct_tree(char* A, int *i)
{
    //Boundary Condition
    if (A == NULL){
            return NULL;
    }

    tree *node = newnode(A[*i]);
    //On reaching leaf node, return
    if (A[*i] == 'L'){
            return node;
    }

    //Populate left sub tree
    *i = *i + 1;
    node->left = construct_tree(A, i);

    //Populate right sub tree
    *i = *i + 1;
    node->right = construct_tree(A, i);

    return node;
}
int main()
{
    char pre[100];
    cin>>pre;
    tree  *root=construct_tree(pre,0);
    inorder(root);
return;
}
