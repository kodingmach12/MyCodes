void InsertAtbottom(Stack *s,int data)
{
    if(isempty(s))
    {
        push(s,data);
        return;
    }
    int temp;
    temp=pop(s);
    InsertAtbottom(s,data);
    push(s,temp);
}
void ReverseStack(Stack *s)
{
    if(isempty(s))  return;
    int data;
    data=pop(s);
    ReverseStack(s);
    InsertAtbottom(s,data);
}
