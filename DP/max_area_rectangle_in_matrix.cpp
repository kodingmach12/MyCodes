    #define ROW 10
    #define COL 10

    int find_max_matrix(int A[ROW][COL])
    {
     int i, j;
     int max, cur_max;
     cur_max = 0;

     //Calculate Auxilary matrix
     for (i=1; i<ROW; i++)
         for(j=0; j<COL; j++)
         {
             if(A[i][j] == 1)
                 A[i][j] = A[i-1][j] + 1;
         }

     //Calculate maximum area in S for each row
     for (i=0; i<ROW; i++)
     {
         max = largestArea(A[i], COL);
         if (max > cur_max)
             cur_max = max;
     }

     //Regenerate Oriignal matrix
     for (i=ROW-1; i>0; i--)
         for(j=0; j<COL; j++)
         {
             if(A[i][j])
                 A[i][j] = A[i][j] - A[i-1][j];
         }

     return cur_max;
    }
