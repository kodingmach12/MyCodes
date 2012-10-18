#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}Node;
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
Node* newNode(int );

bool isBST(Node* root, int& prev){
	if(!root)	return true;
	if(isBST(root->left,prev)){
		if(root->data > prev){
			prev = root->data;
			return isBST(root->right,prev);
		}
		else 
			return  false;
	}
	else 
		return false;
}
int countLeaf(Node* root)
{
	if(!root)	return 0;
	if(!root->left && !root->right)	return 1;
	return countLeaf(root->left)+countLeaf(root->right);
}
void printpaths(Node* p)
{
	if(!p)	return;
	if(!p->left && !p->right){
		printf(" %d \n",p->data);

	}
	if(p->left){
		printf(" %d ",p->data);
		printpaths(p->left);
	}
	if(p->right){
		printf(" %d ",p->data);
		printpaths(p->right);
	}
	
}

int main()
{
/* 4
2 3
1 3 8
*/



  Node *root = newNode(8);

  root->left = newNode(4);
  root->left->left = newNode(2);
  root->left->left->left = newNode(1);
  root->left->left->right = newNode(3);
  root->left->right = newNode(6);
  root->left->right->left = newNode(5);
  root->left->right->right = newNode(7);

  root->right = newNode(12);
  root->right->left = newNode(10);
  root->right->left->left = newNode(9);
  root->right->left->right = newNode(11);
  root->right->right = newNode(14);
  root->right->right->left = newNode(13);
  root->right->right->right = newNode(15);


	inorder(root);
	int prev = -1;
	if(isBST(root,prev))
		printf("\nBST\n");
	else
		printf("\nNot a BST\n");
	printf("all paths \n");
	printpaths(root);
	printf("Total leaves are %d \n",countLeaf(root));

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
    if(!root) return;
    inorder(root->left);
    cout<<" "<<root->data;
    inorder(root->right);
}
void preorder(Node *root)
{
    if(!root) return;
    cout<<" "<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<" "<<root->data;
}



