struct node * search(struct node *link)
{
if(link==null)
return null;

struct linknode * left=search(link->treenode->left);
struct linknode * right=search(link->treenode->right);
int l=0,r=0;

struct linknode *lnk=malloc(sizeof(struct linknode));

if(left)
l=left->sum;

if(right)
r=right->sum;
struct linknode *tmp;
if(l>r)
{
tmp->sum=left->sum+link->treenode->value;
tmp->next=left;
}
else
{
tmp->sum=right->sum+link->treenode->value;
tmp->next=right;
}
return tmp;

}