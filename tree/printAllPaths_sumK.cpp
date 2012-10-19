#include <iostream>
#include<vector>
using namespace std;

typedef struct node
{
    int data;
    struct node *left,*right;
}Node;
//Assumptions- all node values are positive
void printVector(vector<Node*> &v,int start,int end)
{
    int i=0;

    for(i=start;i<end;i++){
        cout<<" "<<v[i]->data<<" ";
    }
    cout<<endl;
}

void printSubArray(vector<Node *> &v,int k)
{
    int sum=0,i,j,end=v.size();

    for(j=0;j<end;j++)
    {
        if(sum>k)
        {
            sum-=v[i]->data;
             i++;
        }
        if(sum==k)
            printVector(v,i,j);

        sum+=v[j]->data;
    }
}

void printAllPaths(Node *root,int k)
{
    if(!root || k<0)   return;
    vector<Node *>  v;
    int sum=0;
    Node *prev=NULL,*current=root,*temp;
    v.push_back(current);
    sum+=current->data;

    while(!v.empty())
    {
        current=v.back();
        if(!prev || prev->left==current || prev->right==current)
        {
            if(current->left)
            {
                v.push_back(current->left);
                sum+=current->left->data;
            }
            else if(current->right)
            {
                v.push_back(current->right);
                sum+=current->right->data;
            }
            else
            {
                if(sum>k)
                    printSubArray(v,k);
                v.pop_back();
                sum-=current->data;
            }
            if(sum==k)
                printVector(v,0,v.size());
        }
        else
        {
            if(current->left==prev)
            {
                if(current->right)
                {
                    v.push_back(current->right);
                    sum+=current->right->data;
                }
                else
                {
                    v.pop_back();
                    sum-=current->data;
                }
            }
            else if(current->right==prev)
            {
                v.pop_back();
                sum-=current->data;
            }
        }
        prev=current;
    }
}
