void writeBinaryTree(Node  *p,FILE *out)
{
    if(!p)  out<<" # ";
    else{
        out<<p->data<<" # ";
        writeBinaryTree(p->left,out);
        writeBinaryTree(p->right,out);
    }
}
void readBinaryTree(Node *p,FILE  *fin)
{
    int token;
    bool isNumber;
    if(!readNextToken(token,fin,isNumber))
        return;
    if(isNumber)
    {

    }
        p=newNode(token);
        readBinaryTree(p->left,fin);
        readBinaryTree(p->right,fin);
    }
}

//*************** Serialize a BST

void readBSTHelper(int min,int max,int &insval,Node *& p,ifstream &fin)
{
    if(insval > min && insval < max)
    {
        int val=insval;
        p=newNode(val);
        if(fin>>insval){
        readBSTHelper(min,val,insval,p->left,fin);
        readBSTHelper(val,max,insval,p->right,fin);
        }
    }
}
