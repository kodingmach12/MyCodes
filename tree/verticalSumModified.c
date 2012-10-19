#include<iostream>
#include<stack>
using namespace std;
int getVerticaLines(Tree *root,int *left,int *right)
{
    if(!root)   return;
    if(!root->left && !root->right)
    {
        *left=0;
        *right=0;
    return;
    }

    *left =inorder(root->left,true);
    *right=inorder(root->right,false);
return (*left+1+*right);
}
int inorder(Tree *root,bool flag)
{
    if(!root)   return 0;
    int max=0,cur=0;
    Stack<Tree *> s;
    Tree *current,*prev=NULL,*temp;
    s.push(root);
    cur++;
while(!s.empty())
{
    current=s.top();
    if(!prev || prev->left==current || prev->right==current)
    {
        if(current->left)
        {
            cur++;
            s.push(current->left);
        }
        else if(current->right)
        {
            cur--;
            s.push(current->right);
        }
        else
            s.pop();
    }
    else if(current->left==prev)
    {
        if(current->right){
            s.push(current->right);
            cur--;}
        else    s.pop();
    }
    else if(current->right==prev)
        s.pop();
    if(flag){
        if(max<cur)
            max=cur;
    }
    else{
        if(cur<max)
            max=cur
    }

    prev=current;
}
if(flag)    return max;
else        return (-max);
}
