#include<iostream>
#include<cstdlib>
#include<cassert>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
}Node;

int  delete_kth_last(Node *&root, int k)
{
    if(!root)  return 0;
    Node *ref_ptr=root;

    while( k  && ref_ptr )
    {
        ref_ptr = ref_ptr -> next;
        k--;
    }

    if(ref_ptr==NULL && k!=0)
    {
        cout<<" Not sufficient node to delete"<<endl;
        return 0;
    }
    else
    {
        Node *main_ptr = root,*prev=NULL;
        while(ref_ptr)
        {
            prev=main_ptr;
            main_ptr    = main_ptr->next;
            ref_ptr = ref_ptr->next;
        }
        if( main_ptr == root)
        {
            Node *temp2=root;
            root = (root)->next;
            free(temp2);
            temp2=NULL;
            return 1;
        }
        else
        {
            prev->next=main_ptr->next;
            free(main_ptr);
            main_ptr=NULL;
        }
    }
return 1;
}
void push(struct node** head_ref, int  new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void printList(Node *head)
{
    if(head)
    {
        while(head)
        {
            cout<<" "<<head->data;
            head=head->next;
        }
        cout<<endl;
    }
}
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

     push(&head, 1);
     push(&head, 2);
     push(&head, 3);
    /* push(&head, 4);
     push(&head, 5);
     push(&head, 6);
     push(&head, 7);*/
     int k;
     int i;
     cin>>k;
     assert(k>0);
     i=k;
   //  for(i=1;i<k;i++)

     {
         printList(head);
         if(delete_kth_last(head,i))
            cout<<" Successful     "<<endl;
         else
            cout<<" Not Successful "<<endl;
         printList(head);
     }
return 0;
}
