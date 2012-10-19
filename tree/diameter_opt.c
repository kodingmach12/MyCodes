#include<stdio.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
int max(int a,int b){
	return (a>b?a:b);
}
bool isleaf(Node *p){
    return (!p->left && !p->right);
}
struct node* newNode(int data){
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = node->right = NULL;
  return(node);
}
int diameter(struct node *root){
    if(!root)   return 0;
    if(isleaf(root))    return 1;
    int height=0;
  return Dopt(root,&height);
}
int Dopt(struct node *root,int *height)
{
		if(root==NULL){
		    *height=0;
			return 0;
		}
		int ld=0,rd=0,lh=0,rh=0;
		ld=Dopt(root->left,&lh);
		rd=Dopt(root->right,&rh);
		*height=max(lh,rh)+1;
	return max(max(ld,rd),lh+rh+1);
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left  = newNode(6);
  printf("Diameter of the given binary tree is %d\n", diameter(root));

  getchar();
return 0;
}
