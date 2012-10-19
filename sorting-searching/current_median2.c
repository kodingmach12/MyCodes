struct node
{
int data,lno,rno;
struct node * left,*right;
};

struct node* createTree(int value)
{
struct node* p=(struct node*)malloc(sizeof(struct node));
p->data=value;
p->lno=p->rno=0;
p->left=p->right=NULL;
}

void AddElem(struct node *root,int value)
{
	if(value >= root->data)
	{	 root->rno++;
		  if(root->right)
			AddElem(root->right,value);
		  else
			root->right=createTree(value);
	}
	else
	{ 	root->lno++;
			if(root->left)
				AddElem(root->left,value);
			else
				root->left=createTree(value);
	}		
}		
int findmedian(struct node *root)
{
	int total= 1+(root->lno)+(root->rno);
	if(total%2==1)
	{
		if(root->lno == root->rno)
		 return root->data;
		else
			if(root->lno < root->rno)
			
			else
	}
	else
	{
	
	}
}		