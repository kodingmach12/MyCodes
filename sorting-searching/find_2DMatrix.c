 
#define MAX 100

bool findmatch_wrapper(char mat[MAX][MAX], char *pat, int nrow, int ncol)
{
    if (strlen(pat) > nrow*ncol)
        return false;
    
    int used[MAX][MAX] = {{0,},};

    return findmatch(mat, pat, used, 0, 0, nrow, ncol, 0);
}

//level: index till which pattern is matched
//x, y: current position in 2D array
bool findmatch(char mat[MAX][MAX], char *pat, int used[MAX][MAX], int x, int y, int nrow, int ncol, int level)
{
    if (level == strlen(pat)) //pattern matched
        return true;
        
    if (nrow == x || ncol == y)
        return false;
        
    if (used[x][y])
        return false;    
    
    if (mat[x][y] != pat[level] && level == 0)
    {
        if (x < (nrow - 1))
            return findmatch(mat, pat, used, x+1, y, nrow, ncol, level); //next element in same row
        else if (y < (ncol - 1))
            return findmatch(mat, pat, used, 0, y+1, nrow, ncol, level); //first element from same column
        else 
            return false;
    }    
    else if (mat[x][y] == pat[level])
    {
        bool res;
        //marking this cell as used
        used[x][y] = 1;       
             
        //finding subpattern in 8 neighbours     
        res = (x > 0                                    ? findmatch(mat, pat, used, x-1, y, nrow, ncol, level+1) :   false) ||
              (res = x < (nrow - 1)                     ? findmatch(mat, pat, used, x+1, y, nrow, ncol, level+1) :   false) ||
              (res = y > 0                              ? findmatch(mat, pat, used, x, y-1, nrow, ncol, level+1) :   false) ||
              (res = y < (ncol - 1)                     ? findmatch(mat, pat, used, x, y+1, nrow, ncol, level+1) :   false) ||
              (res = x < (nrow - 1) && (y < ncol -1)    ? findmatch(mat, pat, used, x+1, y+1, nrow, ncol, level+1) : false) ||
              (res = x < (nrow - 1) && y > 0            ? findmatch(mat, pat, used, x+1, y-1, nrow, ncol, level+1) : false) ||
              (res = x > 0 && y < (ncol - 1)            ? findmatch(mat, pat, used, x-1, y+1, nrow, ncol, level+1) : false) ||
              (res = x > 0 && y > 0                     ? findmatch(mat, pat, used, x-1, y-1, nrow, ncol, level+1) : false);

        //marking this cell as unused
        used[x][y] = 0;
        return res;
    }
    else
        return false;
}

