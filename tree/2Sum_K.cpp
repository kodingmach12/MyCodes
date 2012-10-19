#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
typedef struct node
{
    int data;
    struct node *left,*right;
}Node;

int find2sum(Node *root,Node *a,Node *b,int k)
{
    if(!root)   return 0;
    stack<Node*> inorder,reverse_inorder;
    Node *cur,*prev=NULL,*rcur,*rprev=NULL;
    int sum=0;
    cur=rcur=root;
    while(cur)
    {
        inorder.push(cur);
        cur=cur->left;
    }
    while(rcur)
        {
        reverse_inorder.push(rcur);
        rcur=rcur->right;
        }

    while(inorder.top()!=reverse_inorder.top()){
    cur=inorder.top();
    rcur=reverse_inorder.top();
    sum=cur->data + rcur->data;
    if(sum==k){
        a=cur;
        b=rcur;
    return 1; }
    if(sum<k)
    {
        if(!prev || prev->left==cur || prev->right==cur){
            if(cur->left)
                inorder.push(cur->left);
            else if(cur->right)
                inorder.push(cur->right);
            else
                inorder.pop();  }
        else  {
            if(cur->left==prev){
                if(cur->right)
                    inorder.push(cur->right);
                else
                    inorder.pop();
            }
            else if(cur->right==prev)
                inorder.pop(); }
        prev=cur;
    }
    else if(sum>k)
    {
        if(!rprev || rprev->left==rcur || rprev->right==rcur){
            if(rprev->right)
                reverse_inorder.push(rprev->right);
            else if(rprev->left)
                reverse_inorder.push(rprev->left);
            else
                reverse_inorder.pop();
        }
        else{
            if(rcur->right==rprev){
                if(rcur->left)
                    reverse_inorder.push(rcur->left);
                else
                    reverse_inorder.pop();
            }
            else if(rcur->left==rprev)
                reverse_inorder.pop();
        }
        rprev=rcur;
    }
  }  //while ends here
  return 0;
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
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
        cout<<" "<<root->data;
    inorder(root->right);

}

int main()
{
/*                12
        4               14
    1       13       10		7

*/
  Node *root = newNode(123);
  root->left        = newNode(4);
  root->right       = newNode(14);
  root->left->left  = newNode(1);
  root->left->right = newNode(13);
  root->right->left = newNode(10);
  root->right->right  = newNode(7);
    int k;
    Node *p=NULL,*q=NULL;
    inorder(root);
    cin>>k;
    find2sum(root,p,q,k);
    if((p->data + q->data) ==k)
        cout<<" "<<p->data<<" "<<q->data<<endl;
    else
        cout<<" Element not found  "<<endl;
return 0;
}
