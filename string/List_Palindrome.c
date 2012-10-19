bool checkPalindrom (struct node1d **left, struct node1d *right) 
{
  if (! right) { /* stop recursion here */
    return true;
  }
 
  bool isp = checkPalindrom(left, right->next);
  if (isp == false)
    return false;
 
  bool isp1 = (right->data == (*left)->data);
  *left = (*left)->next; /* save next pointer */
 
  return isp1;
}