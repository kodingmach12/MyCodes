#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct node
{
    int data;
    struct node *left,*right;
}Node;
void reverse_ZigZag(Node *root)
{
    if(!root)   return ;
    stack<Node *> s;
    queue<Node *> q;
    int thislevel=0,nextlevel=0;
    Node *current=root;
    q.push(current);
    thislevel++;
    bool ltr=true;
    while(!q.empty())
    {
        current=q.front();
                q.pop();
        thislevel--;
        s.push(current);
        if(ltr){
            if(current->left){
                 q.push(current->left);
                 nextlevel++;
            }
            if(current->right){
                 q.push(current->right);
                 nextlevel++;
            }
        }
        else{
            if(current->right){
                 q.push(current->right);
                 nextlevel++;
            }
            if(current->left){
                 q.push(current->left);
                 nextlevel++;
            }
        }
        if(thislevel==0)
        {
            cout<<" ltr = "<<ltr<<endl;
            ltr=!ltr;
            thislevel=nextlevel;
            nextlevel=0;
        }
    }
    while(!s.empty()){
        cout<<" "<<s.top()->data;
        s.pop();
    }
    cout<<endl;
}
Node* newNode(int n)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    if(temp){
        temp->left=temp->right=NULL;
        temp->data=n;
    }
return temp;
}
int main()
{

    Node *root=NULL;
  root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->left->left->left  = newNode(8);
  root->left->left->right  = newNode(9);
  root->right->right->left = newNode(10);
  root->right->right->right = newNode(11);
    reverse_ZigZag(root);
return 0;
}
