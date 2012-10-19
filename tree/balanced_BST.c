#include<stdio.h>
// BALANCED BST A/T NO OF NODES IN THE BST , NO OF NODES IN THE lEFT-BST IS ALWAYS = , >BY 1 TO R-BST

typedef struct node
{
    struct node* left;
    int data,lcnt,rcnt;
	struct node* right;
}Node;

Node* newNode(int n)
{
    Node* tmp=(Node*)malloc(sizeof(Node));
    tmp->data=n;
    tmp->lcnt=0;
    tmp->rcnt=0;
    tmp->left=NULL;
    tmp->right=NULL;
return tmp;
}

Node* insert(struct node *root,int n)
{
    if(root==NULL)
    {
        root=newNode(n);
    }
    else
    {
        if(n >= root->data)
        {
            root->rcnt++;
                if(!root->right)
                    root->right=newNode(n);
                else
                    insert(root->right,n);
        }
        else
        {
            root->lcnt++;
            if(!root->left)
                root->left=newNode(n);
            else
                insert(root->left,n);
        }
    }
return root;
}

int median(Node *root,Node *in_suc)
{
    if(root=NULL)
        return -1;
    int totalelem= root->lcnt + root->rcnt + 1;
    int pos1=0,pos2=0;
    if(totalelem%2)
    {
        return (root->data+in_suc->data)/2;
    }
    else
    {
        return root->data;
    }
}

void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);

    printf("\nlcnt=%d  data=%d rcnt=%d",root->lcnt,root->data,root->rcnt);
    inorder(root->right);
}

int main()
{
int n=0,i=0;
Node *root=NULL;
while(i++<5)
{
    scanf("%d",&n);
    root=insert(root,n);
//    printf("\nThe current median  is %d",median(root));
}
inorder(root);
return 0;
}
