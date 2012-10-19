#include<iostream>
#include<cstdlib>
#include<algorithm>
#define stacksize 100
using namespace std;
class three_stack_one_array
{
    int stacks[3*stacksize];
    int stacktop[3];
    public:
    three_stack_one_array()
    {
        stacktop[0]=-1;
        stacktop[1]=-1;
        stacktop[2]=-1;
    }

    void push(int stacknum,int value)
    {
        if(stacknum>=1 && stacknum<=3)
        {
            int top=stacktop[stacknum-1] ;
            if( (top+1) < (stacksize ) )
            {
                int index     = top + 1 + (stacknum-1)*stacksize;
                stacks[index] = value;
                stacktop[stacknum-1]+= 1;
            }
            else
                cout<<" Error : Stack overflow "<<endl;
        }
        else
            cout<<" Invalid stack number "<<endl;
    }

    int pop(int stacknum)
    {
        if(stacknum>=1 && stacknum<=3)
        {
            int top=stacktop[stacknum-1];
            if( top ==-1 )
                cout<<" Error : Stack underflow "<<endl;
            else
            {
                stacktop[stacknum-1]-= 1;
            }
        }
        else
            cout<<" Invalid stack number "<<endl;
    }

    int top(int stacknum)
    {
        if(stacknum>=1 && stacknum<=3)
        {
            int top=stacktop[stacknum-1];
            if( top ==-1 )
                cout<<" Error : No element "<<endl;
            else
            {
                return  stacktop[top+stacknum*stacksize];
            }
        }
        else
            cout<<" Invalid stack number "<<endl;
    }

    bool isempty(int stacknum)
    {
        return (stacktop[stacknum-1]==-1);
    }
};
int main()
{
    three_stack_one_array s;
    int n,k,elem,stacknum;
    while(1)
    {
        cin>>stacknum;
        if(stacknum==-1)   break;
        cout<<" input stack number ";
        cout<<" 1: push"<<endl;
        cout<<" 2: pop"<<endl;
        cout<<" 3: top"<<endl;
        cout<<" 4: size"<<endl;
        cout<<" 5: break"<<endl;
        cin>>k;
        switch(k)
        {
            case 1:
            {
                cin>>elem;
                s.push(stacknum,elem);
            }
            case 2:
            {
                s.pop(stacknum);
            }
            case 3:
            {
                cout<<" the top element of stack "<<s.top(stacknum);
            }
            case 4:
            {
                cout<<" The size of stack "<<stacknum<<" is "<<s.isempty(stacknum);
            }
            case 5:
                break;
        }

    }

}
