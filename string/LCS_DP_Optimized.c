//Space-efficient LCS:

int lcs_length(char * A, char * B)
{
	allocate storage for one-dimensional arrays X and Y
	for (i = m; i >= 0; i--)
	{
	    for (j = n; j >= 0; j--)
	    {
		if (A[i] == '\0' || B[j] == '\0') X[j] = 0;
		else if (A[i] == B[j]) X[j] = 1 + Y[j+1];
		else X[j] = max(Y[j], X[j+1]);
	    }
	    Y = X;
	}
return X[0];
}
