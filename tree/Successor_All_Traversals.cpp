#include <stdio.h>
class BinaryTree
{
    private:
        int data;
        BinaryTree *left, *right;

    public:
        BinaryTree(int d):data(d), left(NULL), right(NULL){}

        ~BinaryTree()
        {
            if(left != NULL)
            {
                delete left;
            }
            if(right != NULL)
            {
                delete right;
            }
        }

    //constructs full binary tree from array
    void makeTree(int a[], int n, int i)
    {
        int l = (i << 1)    + 1;

        if(l < n)
        {
            left = new BinaryTree(a[l]);
            left->makeTree(a, n, l);

            int r = l  + 1;

            if(r < n)
            {
                right = new BinaryTree(a[r]);
                right->makeTree(a, n , r);
            }
        }
    }


    /*
    Return Value;
        0: Success
        1: Found
        2: Not Found

        if Success *ret == successor of the element ele

        Algorithm:
        if element is not leaf, if left is there left is the successor else right is the successor
        if element is leaf, we will find the ancestor which has right, that right is the successor
    */

    int preorderSucc(int ele, int *ret)
    {
        if(data == ele) //element found
        {
            if(left != NULL) //left is there, left is the ancestor
            {
                *ret = left->data;
                return 0;
            }

            if(right != NULL) //right is there, right is the ancestor
            {
                *ret = right->data;
                return 0;
            }
            return 1; //element is the leaf
        }

        int rc;

        if(left != NULL)//find in left subtree
        {
            rc = left->preorderSucc(ele, ret);

            if(rc == 0) //already success, break the recursion
                return 0;

            if(rc == 1)
            {
                if(right != NULL)//this is the ancestor which has right, then right is the successor
                {
                    *ret = right->data;
                    return 0;
                }

                return 1; //go up
            }
        }

        if(right != NULL) //find in right subtree
        {
            return right->preorderSucc(ele, ret);

        }

        return 2; //not found
    }
int inorderSucc(int ele, int *ret)
{
        if(data == ele) //element found
        {
            if(right != NULL) //right is there, left most node is the successor
            {
                BinaryTree *p = right;
                while(p->left) //to find left most
                    p = p->left;
                *ret = p->data;
               return 0;
            }
            return 1; //no right
        }
        int rc;
        if(left != NULL)//find in left subtree
        {
            rc = left->inorderSucc(ele, ret);
            if(rc == 0) //already success, break the recursion
                return 0;
            if(rc == 1) //current node is the successor
            {
                *ret = data;
                return 0; //go up
            }
        }
        if(right != NULL) //find in right subtree
            return right->inorderSucc(ele, ret);
return 2;
}

    int postorderSucc(int ele, int *ret)
    {
        if(data == ele) //element found
        {
            return 1; //bubble up
        }

        int rc;

        if(left != NULL)//find in left subtree
        {
            rc = left->postorderSucc(ele, ret);

            if(rc == 0) //already success, break the recursion
                return 0;

            if(rc == 1)
            {
                if(right != NULL)//if right is there, left most the successor
                {
                    BinaryTree *p = right;

                    while(p->left) //to find the leftmost
                        p = p->left;

                    *ret = p->data;
                }
                else
                    *ret = data;
                return 0;

            }
        }

        if(right != NULL) //find in right subtree
        {
            rc = right->postorderSucc(ele, ret);

            if(rc == 0) //already success, break the recursion
                return 0;

            if(rc == 1)//current node is the successor
            {
                *ret = data;
                return 0;
            }
        }

        return 2;
    }


    //prints the preorder traversal of the binary tree
    void preorder()
    {
        printf("%d ", data);

        if(left)
            left->preorder();

        if(right)
            right->preorder();
    }

    //prints the inorder traversal of the binary tree
    void inorder()
    {
        if(left)
            left->inorder();

        printf("%d ", data);

        if(right)
            right->inorder();
    }

    //prints the postorder traversal of the binary tree
    void postorder()
    {
        if(left)
            left->postorder();

        if(right)
            right->postorder();

        printf("%d ", data);
    }
};

int main()
{
    int n;

    scanf("%d", &n);

    int i;

    int a[n];

    for(i = 0; i <n; ++i)
        scanf("%d", a + i);


    BinaryTree t(a[0]);

    t.makeTree(a, n, 0);

/*
    printf("\npreorder is \n");

    t.preorder();
    printf("\npostorder is\n");
    t.postorder();
*/

    printf("\ninorder is\n");
    t.inorder();
    printf("\n");

    int elm;

    printf("\nEnter element to which successor to be found: ");
    scanf("%d", &elm);


    int suc;

//  int rc = t.preorderSucc(elm, &suc);
    int rc = t.inorderSucc(elm, &suc);
//  int rc = t.postorderSucc(elm, &suc);


    switch(rc)
    {
        case 0:
            printf("\nsucc of %d is %d\n", elm, suc);
            break;

        case 1:
            printf("\nNo successor as it is the last element\n");
            break;

        case 2:
            printf("\nElement is not found in tree\n");
            break;
    }
    return 0;
}
