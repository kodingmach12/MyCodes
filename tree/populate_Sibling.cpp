//Method 1:- works only for complete Binary Tree
void populateSibling_BFS(Node *p)
{
    if(!p)  return;
    queue<Node*> q;
    Node *curNode=root;
    int thislevel=0,nextlevel=0;
    q.push(curnode);
    thislevel++;

while(!q.empty())
{
    curNode=q.pop();
    thislevel--;
    if(curNode->left)
    {
        q.push(curNode->left)
        nextlevel++;
    }
    if(curNode->right)
    {
        q.push(curNode->right);
        nextlevel++;
    }
    if(thislevel)
        curNode->sibling=q.fron();
    else{
        curNode->sibling=NULL;
        swap(thislevel,nextlevel);
    }

}

}
