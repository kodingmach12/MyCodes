#define bool int
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
    char data;
    struct node* next;
};

bool isPalindrome(struct node **left, struct  node *right)
{
   /* stop recursion here */
   if (!right)
      return true;
   /* If sub-list is not palindrome then no need to
       check for current left and right, return false */
   bool isp1 = isPalindrome(left, right->next);
   if (isp1 == false)
      return false;
   /* Check values at current left and right */
   bool isp2 = (right->data == (*left)->data);
   /* Move left to next node */
   *left = (*left)->next; /* save next pointer */
   return isp2;
}
/* UTILITY FUNCTIONS */
/* Push a node to linked list. Note that this function
  changes the head */
void push(struct node** head_ref, char new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to pochar to the new node */
    (*head_ref)    = new_node;
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

     push(&head, 'r');
     push(&head, 'a');
     push(&head, 'd');
     push(&head, 'a');
     push(&head, 'r');

     /* r->a->d->a->r*/
     if(isPalindrome(&head, head) == 1)
       printf("Linked list is Palindrome");
     else
       printf("Linked list is not Palindrome");

     getchar();
     return 0;
}
