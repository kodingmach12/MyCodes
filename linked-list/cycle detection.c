//brent's algorithm

bool findLoop(struct node* head)
{
    if (head == NULL)
        return false;
    struct node* slow = head;
    struct node* fast = head;
    int i = 0;
    int k = 1;
 
    while (slow != NULL)
    {
        slow = slow->next;
        i++;
        if (slow == fast)
            return true;
        if (i == k)
        {
            fast = slow;
			k*= 2;
        }
    }
    return false;
}
