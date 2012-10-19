typedef struct Node
{
    int data;
    struct node *left,*right;
}Node;
typedef struct NodeInfo
{
    int data;
    int level;
    Node *node;
}NodeInfo;
int comparator(const NodeInfo *a, const NodeInfo *b)
{
    return a->level - b->level;
}

Node* makeTree( int ancestors[][n], int n)
{
    NodeInfo levels[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        levels[i].data=i;
        levels[i].level=0;
        for(j=0;j<n;j++)
            levels[i].level += ancestors[i][j];
    }
    qsort(levels, n, sizeof(NodeInfo), comparator);
    if(levels[0].level!=0)
        return NULL;
    Node *root = (Node*)calloc(1,sizeof(Node));
    root->data = levels[0].data;
    levels[0].node=root;

    Node *temp;
    int prevLevelStart=0, curLevelStart=0, curLevel=0;

    for(i=1;i<n;i++)
    {
        temp            =   (Node*)calloc(1,sizeof(Node));
        temp->data      =   levels[i].data;
        levels[i].node  =   temp;

        if(curLevel != curLevelStart)
        {
            prevLevelStart = curLevelStart;
            curLevelStart  =  i;
            curLevel       = levels[i].level;
        }

        for(j=prevLevelStart; j<curLevelStart; j++)
        {
            int child=levels[i].data;
            int parent=levels[j].data;
            if( ancestors[child][parent] )
            {
                Node *parentnode=levels[j].node;
                if(!parentnode->left)
                    parentnode->left=temp;
                if(!parentnode->right)
                    parentnode->right=temp;
                else
                {
                    cout<<" Bad Input "<<endl;
                    return NULL;
                }
                break;
            }
        }
    }
return root;
}
