#include<iostream>
#include<cstdio>
#include<vector>
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
void treeToDLL(Node* root, Node*& prev, Node*& head);

int main()
{
/*          4
        2       3
    1       3       8
*/



  Node *root        = newNode(8);

  root->left        = newNode(4);
  root->left->left  = newNode(2);
  root->left->left->left    = newNode(1);
  root->left->left->right   = newNode(3);
  root->left->right = newNode(6);
  root->left->right->left   = newNode(5);
  root->left->right->right  = newNode(7);

  root->right        = newNode(12);
  root->right->left  = newNode(10);
  root->right->left->left    = newNode(9);
  root->right->left->right   = newNode(11);
  root->right->right = newNode(14);
  root->right->right->left   = newNode(13);
  root->right->right->right  = newNode(15);

	inorder(root);
	printf("\n=======\n");
	Node* head = NULL;
	Node* prev = NULL;
	treeToDLL(root,prev,head);
	Node* temp = head;
	while(temp->right!=head){
		printf(" %d ",temp->data);
		temp = temp->right;
	}


return 0;
}
void treeToDLL(Node* p, Node*& prev, Node*& head){
	if(!p)	return;
	treeToDLL(p->left, prev, head);
	p->left = prev;
	if(prev)
		prev->right = p;
	else
		head = p;
	Node* right = p->right;
	head->left = p;
	p->right = head;
	prev = p;
	treeToDLL(right,prev,head);
}
Node* newNode(int val){
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp){
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

