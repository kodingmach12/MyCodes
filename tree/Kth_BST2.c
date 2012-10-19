int kthMin(BinarySearchTree *t, int *k) {
 
    if(t == NULL)
        return INT_MAX;
 
    int x = kthMin(t->left, k);
 
    if(x != INT_MAX) return x;
 
    (*k)--;

    if(*k == 0) return t->data;
 
    return kthMin(t->right, k);
}
