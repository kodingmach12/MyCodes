#include<stdio.h>
void readBSTHelper(int min,int max,int &insertval,Node *&p,FILE *fin)
{
    if(insertval > min && insertval < max)
    {   val=insertval;
        p=newNode(val);
        if(fin>>insertval)
        {
        readBSTHelper(min,val,insertval,p->left,fin);
        readBSTHelper(val,max,insertval,p->right,fin);
        }
    }
}
void  readBST(FILE  *fin)
{
    if(!fin)    return;
    int val;
    fin>>val;
    Node *root=NULL;
    readBSTHelper(INT_MIN,INT_MAX,val,root,fin);
}
