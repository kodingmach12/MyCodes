#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;


typedef Node *Tree;

typedef struct Level
{
    int data;
    int level;
    Node *node;
}Level;

int sortLevel(const void *a, const void *b)
{
    const Level *x = a;
    const Level *y = b;

    return x->level - y->level;

}

/*
    constructs a binary tree from ancestor matrix
    returns NULL, if matrix is invalid
*/

Tree constructTreeFromAncestorMatrix(int n, int ancestors[n][n])
{
    //Calculate level of each node (level is the num of ancestor nodes)
    Level levels[n];

    int i, j;

    for(i = 0; i < n; i++)
    {
        levels[i].data = i;
        levels[i].level = 0;

        for(j = 0; j < n; j++)
            levels[i].level += ancestors[i][j];
    }

    //sort nodes based on level
    qsort(levels, n, sizeof(Level), sortLevel);


    //first node level should be zero
    if(levels[0].level != 0)
        return NULL;

    //Construct root node;
    Tree t = (Node *)calloc(1, sizeof(Node));
    t->data = levels[0].data;
    levels[0].node = t;


    //Link nodes to the  ancestor in prev level
    Node *node;

    int prevLevelStart = 0;
    int levelStart = 0;
    int curlevel = 0;

    for(i = 1; i < n; i++)
    {
        //allocate the node
        node = (Node *)calloc(1, sizeof(Node));
        node->data = levels[i].data;
        levels[i].node = node;

        //Check level change
        if(curlevel != levels[i].level)
        {
            prevLevelStart = levelStart;
            levelStart = i;
            curlevel = levels[i].level;
        }

        //find the parent in prev level
        for(j = prevLevelStart; j <levelStart; j++)
        {
            if(ancestors[levels[i].data][levels[j].data])
            {
                //attach to left or right based on free slot
                Node *parent = levels[j].node;
                if(!parent->left)
                {
                    parent->left = node;
                }
                else if(!parent->right)
                {
                    parent->right = node;
                }
                else //invalid binary tree
                {
                    return NULL;
                }

                break;
            }
        }
    }

    return t;
}
void preorder(Tree t)
{
    if(!t) return;

    printf("%d\n", t->data);

    preorder(t->left);
    preorder(t->right);
}


int main()
{
    int n;

    scanf("%d", &n);


    int matrix[n][n];

    int i, j;

    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            scanf("%d", &(matrix[i][j]));


    Tree t = constructTreeFromAncestorMatrix(n, matrix);

    preorder(t);

}
