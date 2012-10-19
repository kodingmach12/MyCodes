//Given a pre-order and post-order traversal , tree can  only be made if each internal node //of the tree has two children
struct node
{
  char data;
  struct node *left;
  struct node *right;
};
static int postIndex = 6;
int search(char in[],int inStrt, int inEnd, char data);
struct node *buildTree(char in[], char pre[], int inStrt, int inEnd);
struct node* newNode(char data);


int search(char arr[], int inStrt, int inEnd, char data)
{
  int i;
  for(i = inStrt; i <= inEnd; i++)
  {
     if(arr[i] == data)
     {
        return i;
     }
  }
}

struct node *buildTree(char post[], char pre[], int inStrt, int inEnd)
{
  if(inStrt > inEnd)
     return NULL;
  // pick the last node from post-order traversal
  // which happens to be the root
  struct node *tNode = newNode(post[postIndex--]);
  // if this node has no childern then return
  if(inStrt == inEnd)
     return tNode;
  // find the index of this node in pre-order traversal
  int inIndex = search(pre, inStrt, inEnd, post[postIndex]);
  tNode->right = buildTree(post, pre, inIndex, inEnd);
  tNode->left = buildTree(post, pre, inStrt+1, inIndex -1);
  return tNode;
}

struct node* newNode(char data)
{
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void printInorder(struct node *root)
{
  if(root == NULL)
    return;
  printInorder(root->left);
  printf(" %c ", root->data);
  printInorder(root->right);
}

main()
{
  char post[] = {'C', 'F', 'G', 'D', 'B', 'E', 'A'};
  char pre[] = {'A', 'B', 'C', 'D', 'F', 'G', 'E'};
  int len = sizeof(post)/sizeof(post[0]);
  int i;
  struct node *root = buildTree(post, pre, 0, len-1);
  printInorder(root);
}
