#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Node;

bool detectLoop(Node* head)
{
    if(!head)   return false;
    Node *cur=head;
    bool res=false;
    while(cur->next)
    {
        if(cur->next->prev!=cur){
            res=true;
            break;
        }
        cur=cur->next;
    }
    if(!res)
    {
        if(cur->next!=NULL || head->prev!=NULL)
            res=true;
    }
return res;
}

void remove_Loop(Node *head)
{




}
int main()
{


return 0;
}
