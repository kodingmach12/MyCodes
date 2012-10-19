#include <stdio.h>
#include <stdlib.h>
typedef struct Tnode
{
    int data;
    struct Tnode *left;
    struct Tnode *right;
} Tnode;
typedef struct List
{
    Tnode *data;
    struct List *link;
} List;
List *head = NULL;
List* createlistnode()
{
    List *n = (List*) malloc(sizeof(List));
    n->data = NULL;
    n->link = NULL;
    return n;
}
Tnode* createnode(int data) {
    Tnode *n = (Tnode*) malloc(sizeof (Tnode));
    n->left = n->right = NULL;
    n->data = data;
    return n;
}

void push(Tnode *root) {
    List *tmp = NULL;
    if (head == NULL) {
        head = createlistnode();
        head->data = root;
        return;
    }
    tmp = createlistnode();
    tmp->data = root;
    tmp->link = head;
    head = tmp;
}

Tnode* pop() {
    List *tmp = NULL;
    Tnode *t=NULL;
    if (head != NULL) {
        tmp = head;
        head = head->link;
        t=tmp->data;
        free(tmp);
    }
    return t;
}

Tnode *BTMirrorIterative(Tnode *root) {
    Tnode *node = NULL, *tmp = NULL;
    if (root == NULL)
        return root;
    while (root) {
        push(root);
        if (root->left != NULL)
            root = root->left;
        else if (root->right != NULL)
            root = root->right;
        else {
            do {
                node = pop();
                tmp = node->left;
                node->left = node->right;
                node->right = tmp;
                if (head == NULL)
                    return root;
                root = head->data;
				} while (root->right == node || root->right == NULL);
            if (root->right != NULL)
                root = root->right;
        }
    }
    return NULL;
}

void inorder(Tnode *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}

int isempty() {
    if (head == NULL)
        return 1;
    return 0;
}

int main(int argc, char** argv) {

    Tnode *root;

    root = createnode(15);

    root->left = createnode(7);
    root->right = createnode(25);

    root->left->left = createnode(3);
    root->left->right = createnode(10);

    root->right->left = NULL;
    root->right->right = createnode(50);

    root->left->right->left = createnode(8);
    root->left->right->right = createnode(12);

    root->left->right->left->left = NULL;
    root->left->right->left->right = createnode(9);

    root->left->right->right->left = createnode(11);
    root->left->right->right->right = createnode(14);

    root->right->right->left = createnode(30);
    root->right->right->right = createnode(55);

    root->right->right->right->left = createnode(52);
    root->right->right->right->right = NULL;
    inorder(root);
    printf("\nGenerating Mirror....\n");
    root = BTMirrorIterative(root);
    inorder(root);

    return (EXIT_SUCCESS);
}



void BTMirrorIterative2(Node *root)
{
if(root==NULL)
	return;
QueueNode q=CreateQueue();
	while(root)
	{
		Node *temp=(dequeue(Q))->data;
		if(temp->left)
			enqueue(q,temp->left);
		if(temp->right)
			enqueue(q,temp->right);
		swap(temp->left,temp->right);
	}
}
