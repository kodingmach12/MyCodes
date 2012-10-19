#include <iostream>
using namespace std;

typedef struct node
{
    char val;
    struct node *left;
    struct node *right;
}tree;
void inorder(tree *p)
{
    if(!p)  return;
    inorder(p->left);
    cout<<" "<<p->val<<" ";
    inorder(p->right);
}

tree* newnode(char c)
{
    tree *node = new(tree);
    node->val = c;
    node->left = node->right = NULL;
    return node;
}

tree* construct_tree(string A, int *i,int len)
{
    //Boundary Condition
    if (*i == len){
            return NULL;
    }

    tree *node = newnode(A[*i]);
    //On reaching leaf node, return
    if (A[*i] == 'L'){
            return node;
    }

    //Populate left sub tree
    *i = *i + 1;
    node->left = construct_tree(A, i,len);

    //Populate right sub tree
    *i = *i + 1;
    node->right = construct_tree(A, i,len);

    return node;
}
int main()
{
    string pre;
    cin>>pre;
    int i=0;
    tree  *root=construct_tree(pre,&i,pre.size());
    inorder(root);
return 0;
}
