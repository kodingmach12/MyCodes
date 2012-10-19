int minDiff_two_arrays(int a[], int m, int b[], int n)
{
    assert(m>0);
    assert(n>0);
    int i=0,j=0,mindiff,adiff,bdiff;
    mindiff=abs(a[0]-b[0]);
    while(i<m && j<n)
    {
        if(abs(a[i]-b[j]) < mindiff  )
            mindiff=abs(a[i]-b[j]);
        adiff=abs(a[i]-b[j+1]);
        bdiff=abs(a[i]-b[j+1]);
        if(adiff==bdiff)
        {
            i++;
            j++;
        }
        else if(adiff>bdiff) i++;
        else j++;
    }

}
