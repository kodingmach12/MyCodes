#include<iostream>
#include<vector>
#include<stack>
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
Node* rightMostLeaf(Node* root)
{
    if(!root)
        return NULL;
    if(!(root->left || root->right))
        return root;
    while(1)
    {
    if(root->right)
        root=root->right;
    else if(root->left)
        root=root->left;
    else
        return root;
    }
}
void printBoundary(Node* root)
{
    if(!root)   return;
    if(!(root->left || root->right) )    {
        cout<<" "<<root->data;
        return;
    }
    Node* rightLeaf=rightMostLeaf(root);

    stack<Node*> s;
    Node *prev=NULL,*current=root;
    s.push(current);
    bool leftflag=true;
    while( !s.empty() ){
        current=s.top();
        if(current==rightLeaf)
            break;
        if(!prev || prev->left==current || prev->right==current){
            if(current->left)
                s.push(current->left);
            else if(current->right)
                s.push(current->right);
            else{
                s.pop();
                leftflag=false;
            }

            if(leftflag)
                    cout<<" "<<current->data;
            else if( !(current->left || current->right))
                    cout<<" "<<current->data;
        }
        else if(current->left==prev)
        {
            if(current->right)
                s.push(current->right);
            else
                s.pop();
        }
        else if(current->right==prev)
                s.pop();
        prev=current;
    }
    while(!s.empty()){
        cout<<" "<<s.top()->data;
        s.pop();
    }
}
int main()
{
/*                  1
        2                       9
    3       6               10        13
  4   5    7  8           11   12   14  15
*/
  Node *root        = newNode(1);

  root->left        = newNode(2);
  root->left->left  = newNode(3);
  root->left->left->left    = newNode(4);
  root->left->left->right   = newNode(5);
  root->left->right = newNode(6);
  root->left->right->left   = newNode(7);
  root->left->right->right  = newNode(8);

  root->right       = newNode(9);
  root->right->left  = newNode(10);
  root->right->left->left    = newNode(11);
  root->right->left->right   = newNode(12);
  root->right->right = newNode(13);
  root->right->right->left   = newNode(14);
  root->right->right->right  = newNode(15);


cout<<endl<<" Inorder representation "<<endl;
inorder(root);
cout<<endl<<" Boundary Nodes "<<endl;
printBoundary(root);
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

