#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node* left;
   struct node* right;
}Node;

//root: Current tree node
//left: this pointer should have the address of in-order predecessor of root
//head: this denoted head of final link list
void _treeToDoublyList(Node *root, Node *prev, Node **head)
{
   if(!root)
        return;
   _treeToDoublyList(root->left, prev,head);

   // current node's left points to previous node
   root->left = prev;
   if (prev)
       prev->right = root; // previous node's right points to current node
   else
       *head = root;        // if previous is NULL that current node is head

   Node *right = root->right; //Saving right node

   //Now we need to make list created till now as circular
   (*head)->left = root;
   root->right = *head;

   //For right-subtree/parent, current node is in-order predecessor
   prev = root;
   _treeToDoublyList(right, prev, head);
}

//Wrapper function
Node* treeToDoublyList(Node *root)
{
   Node *prev = NULL;
   Node *head = NULL;
  //printf("in");
   _treeToDoublyList(root, prev, &head);
   return head;
}


/* Create a new node */
static Node* newNode(int data)
{
    Node *node = (Node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
/* Add a new node into a tree */
static void treeInsert(Node** rootRef, int data)
{
    Node *root = *rootRef;
    if (root == NULL)
        *rootRef = newNode(data);
    else
    {
        if (data <= root->data)
            treeInsert(&(root->left), data);
        else
            treeInsert(&(root->right), data);
    }
}
static void printList(Node *head)
{
    Node *current = head;

    while(current != NULL) {
        printf("%d ", current->data);
        current = current->right;
        if (current == head) break;
    }
    printf("\n");
}
void inorder(Node *root)
{
//printf("in");
    if(root==NULL)
        return;
    inorder(root->left);
    printf(" %d",root->data);
    inorder(root->right);
}
/* Demo that the code works */
int main()
{
    Node *root = NULL;
    Node *head=NULL;

    treeInsert(&root, 4);
    treeInsert(&root, 2);
    treeInsert(&root, 1);
    treeInsert(&root, 3);
    treeInsert(&root, 5);
    treeInsert(&root, 6);
    treeInsert(&root, 7);
    treeInsert(&root, 8);
    treeInsert(&root, 9);
printf("\nThe root data is %d\n",root->data);
inorder(root);
printf("\n");
    head=treeToDoublyList(root);
    //head = treeToList(root);
	    printList(head);    /* prints: 1 2 3 4 5  */
printf("\n");
return 0;
}
