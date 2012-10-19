#include<stdio.h>
#define MAX 100
typedef struct stack
{
    struct node* info[MAX];
    int top;
}stack;
typedef struct node
{
	struct node *left;
	int data;
	struct node *right;
}Node;
void push(stack s,Node *item);
{
    if(s.top==MAX-1)
        return; //overflow
    top++;
    s.info[top]=item;

}
void pop(stack s)
{
    top--;
    s.info[(top+1)]=NULL;
}
Node* top(stack s)
{
    if(top==-1)
        return NULL;
    return s.info[top];
}
Node* newNode(int k)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    if(temp)
    {
        temp->data=;
        temp->left=NULL;
        temp->right=NULL;
    }
return temp;
}

void preorder(Node *root)
{
if(!root)
    return;
Stack s;
s.push(root);
Node *prev=NULL;
    while(!isempty(s)){
        Node *current=s.top();
        if(!prev || prev->left==current  || prev==current->right){
            if(current->left)
                s.push(current->left);
            else if(current->right)
                s.push(current->right);
            else{
                printf(" %d ",current->data);
                s.pop();
            }
        }
        else{
            if(current->left == prev){
                if(current->right)
                    s.push(current->right);
                else{
                    printf(" %d ",current->data);
                    s.pop();
                }
            }
            else if(current->right==prev){
                printf("%d",current->data);
                s.pop();
            }
        }
        prev=current;}
}

int main()
{
Node *root=newNode(8);
root->left=newNode(6);
root->right=newNode(10);
root->left->left=newNode(4);
root->left->right=newNode(7);



return 0;
}
