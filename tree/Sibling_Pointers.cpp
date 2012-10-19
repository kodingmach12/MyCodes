#include<iostream>
#include<queue>
using namespace std;
typedef struct node
{
    int data;
    struct node *left,*right,*leftsibling,*rightsibling;
}Node;
void populate_Sibling_Pointers(Node *root)
{
    if(!root)   return;
    if(!root->left && !root->right)     return;

    Node *p=root,prev=NULL;
    queue< Node* > thislevel,nextlevel;
    int cur=0,next=0;
    thislevel.push(root);
    cur++;
    while(!thislevel.empty())
    {
        p=thislevel.top();
        thislevel.pop();
        p->leftsibling=prev;
        if(prev)
            prev->rightsibling=p;
        cur--;
        if(p->left){
            nextlevel.push(p->left);
            next++;
        }
        if(p->right){
            nextlevel.push(p->right);
            next++;
        }
        if(cur==0)
        {   cur=next;
            next=0;
            swap(thislevel,nextlevel);
            prev=NULL;
        }
        prev=cur;
    }

}
