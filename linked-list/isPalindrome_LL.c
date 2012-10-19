/* Program to check if a linked list is palindrome */
#include<stdio.h>
#include<stdlib.h>
#define bool int

/* Link list node */
struct node
{
    char data;
    struct node* next;
};

void reverse(struct node**);
bool compareLists(struct node*, struct node *);

/* Function to check if given linked list is
  palindrome or not */
bool isPalindrome(struct node *head)
{
   struct node *slow_ptr = head;
   struct node *fast_ptr = head;
   struct node *second_half;
   struct node *prev_of_slow_ptr = head;
   char res;

   if(head!=NULL)
   {
       /* Get the middle of the list. Move slow_ptr by 1
         and fast_ptrr by 2, slow_ptr will have the |_n/2_|th
         node */
       while((fast_ptr->next)!=NULL &&
               (fast_ptr->next->next)!=NULL)
       {
          fast_ptr = fast_ptr->next->next;

          /*We need previous of the slow_ptr for
           linked lists  with odd elements */
          prev_of_slow_ptr = slow_ptr;
          slow_ptr = slow_ptr->next;
       }

       /* Case where we have even no of elements */
       if(fast_ptr->next != NULL)
       {
         second_half = slow_ptr->next;
         reverse(&second_half);
         slow_ptr->next = NULL;
         res = compareLists(head, second_half);

         /*construct the original list back*/
         reverse(&second_half);
         slow_ptr->next = second_half;
       }

       /* Case where we have odd no. of elements. Neither first
          nor second list should have the middle element */
       else
       {
          second_half = slow_ptr->next;
          prev_of_slow_ptr->next = NULL;
          reverse(&second_half);
          res = compareLists(head, second_half);

         /*construct the original list back*/
         reverse(&second_half);
         prev_of_slow_ptr->next = slow_ptr;
         slow_ptr->next = second_half;
       }

       return res;
   }
}

/* Function to reverse the linked list  Note that this
    function may change the head */
void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/* Function to check if two input lists have same data*/
int compareLists(struct node* head1, struct node *head2)
{
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while(temp1 && temp2)
    {
       if(temp1->data == temp2->data)
       {
          temp1 = temp1->next;
          temp2 = temp2->next;
       }
       else return 0;
    }

    /* Both are empty reurn 1*/
    if(temp1 == NULL && temp2 == NULL)
       return 1;

    /* Will reach here when one is NULL
      and other is not */
    return 0;
}

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

     push(&head, 'p');
     push(&head, 'e');
     push(&head, 'e');
     push(&head, 'p');

     /* p->e->e->p */
     if(isPalindrome(head) == 1)
       printf("Linked list is Palindrome");
     else
       printf("Linked list is not Palindrome");

     getchar();
     return 0;
}
