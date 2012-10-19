void remove_Adjacent_Pairs(string s)
{
    int i=0,j=0;
    i=1;
    while(s[i]!='\0')
    {
            while( s[i]==s[j] && j>0 )
            {
                i++;
                j--;
            }
            s[++j] = s[i];

        i++;
    }
}
