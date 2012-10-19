#include<stdio.h>
typedef struct node
{
    struct node *next;
	int data;
}List;
typedef struct tnode
{
    struct tnode* left;
    int data;
    struct tnode* right;
}Tnode;
List* getmiddleNsplit(List* head)
{
    List* slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
return slow;
}
Tnode* convert2BST(List *head)
{
    if(head==NULL)
        return NULL;
    List *middle,*l,*r;
    getmiddleNsplit(l,middle,r);
    Tnode* root=(Tnode*)malloc(sizeof(Tnode));
    Tnode->data=middle->data;
    Tnode->left=convert2BST(l);
    Tnode->right=convert2BST(r);
}
int main()
{


}
