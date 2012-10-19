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
    List *n = (List*) malloc(sizeof (List));
    n->data = NULL;
    n->link = NULL;
    return n;
}

Tnode* createnode(int data) 
{
    Tnode *n = (Tnode*) malloc(sizeof (Tnode));
    n->left = n->right = NULL;
    n->data = data;
    return n;
}

void push(Tnode *root) 
{
    List *tmp = NULL;
    if (head == NULL) 
	{
        head = createlistnode();
        head->data = root;
        return;
    }
    tmp = createlistnode();
    tmp->data = root;
    tmp->link = head;
    head = tmp;
}

Tnode* pop() 
{
    List *tmp = NULL;
    Tnode *t=NULL;
    if (head != NULL) 
	{
        tmp = head;
        head = head->link;
        t=tmp->data;
    }
    return t;
}

int isBSTiterative(Tnode *root) 
{
    int prev = -99999;
    Tnode *node = NULL;
    while (root) 
	{
        push(root);
        if (root->left == NULL) 
		{
            do 
			{
                node = pop();
                if (node->data < prev)
                    return 0;
                prev = node->data;
                root = node->right;
            } while (root == NULL && isempty() != 1);
        } 
		else 
		{
            root = root->left;
        }
    }
    return 1;
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

    root->right->right->right->left = createnode(2);
    root->right->right->right->right = NULL;

    printf("%d", isBSTiterative(root));

    return (EXIT_SUCCESS);
}


int isBSTiterative(Node *root)
{
	int prev=INT_MIN;
		while(root)
		{
			push(root);
			if(root->left==NULL)
			{
				do{
				node=pop(p);
				if(node->data < prev)
					return  0;
				prev=node->data;
				root=root->right;
				}while(root==NULL && !isempty(p));
			}
			else
				root=root->left;
		}	
	return 1;
}
