void verticalsum(Node *root)
{
Node *p=root;
if(root==NULL)
	return NULL;
Node *temp;
int cnt=0;
while(p->left!=NULL)
{
cnt++;
p=p->left;
}	
p=root;
while(p->right!=NULL)
{
cnt++;
p=p->right;
}	
cnt+=1;				//this is the size of array to be allocated for storing the vertical sum     

int *vsum=(int *)malloc(sizeof(int)*cnt);

int leftelem = left(root);
(*vsum+leftelem)=root->data;

// now go to left  and 
if(root->left)
	(*vsum+leftelem-1)=root->left->data;	

if(root->right)
	(*vsum+leftelem+1)=root->right->data;	

}