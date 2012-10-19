
int ** alloc2d(int row,int col)
{
int i=0;
int **ptr=NULL;
int **ptr=(int**)malloc(row * sizeof(int*));
    if(*ptr)
    {
    for(i=0;i<row;i++)
        ptr[i]=(int*)malloc(col * sizeof(int));
    }
    else
        cout<<" Memory Error !! "<<endl;
return ptr;
}

// LCS using bottom-up dynamic programming (Tabulation)
int lcs_length(char * A, char * B)
{
	//allocate storage for array L;
	int i=0,j=0;
	int **L=alloc2d(m,n);
	for (i = m; i >= 0; i--)
	    for (j = n; j >= 0; j--)
	    {
		if (A[i] == '\0' || B[j] == '\0')
                L[i,j] = 0;
		else if (A[i] == B[j])
                L[i,j] = 1 + L[i+1, j+1];
		else
                L[i,j] = max(L[i+1, j], L[i, j+1]);
	    }
	return L[0,0];
}
