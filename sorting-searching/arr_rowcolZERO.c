#include<stdio.h>
int main()
{
	int row,col;
	scanf("%d%d",&row,&col);
	int arr[row][col];
	int i=0,j=0,k=0,rowflg=0,colflg=0;

	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d",&arr[i][j]);
	printf("\nThe original input array is -->\n");
	for(i=0;i<row;i++)
	{
    	for(j=0;j<col;j++)
			printf("  %d",arr[i][j]);
	printf("\n");
	}

	for(j=0;j<col;j++)
	  if(arr[0][j]==0)
	     rowflg=1;

	for(j=0;j<row;j++)
	  if(arr[j][0]==0)
	     colflg=1;

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(arr[i][j]==0)
			{
			arr[0][j]=0;
			arr[i][0]=0;
			}
		}
	}

	for(i=1;i<row;i++)
	{
		if(arr[i][0]==0)
		 { 		// set that row to 0
		  for(k=1;k<col;k++)
			arr[i][k]=0;
		 }
	}

	for(j=1;j<col;j++)
	{
		if(arr[0][j]==0)
		{   	// set that col to 0
			for(k=1;k<row;k++)
			   arr[k][j]=0;
		}
	}

	if(rowflg)
	 for(j=0;j<col;j++)	//set row0 to 0
		arr[0][j]=0;

	if(colflg)
	 for(i=0;i<row;i++)//set col0 to 0
		arr[i][0]=0;

	printf("\nThe final converted array is -->\n");
	for(i=0;i<row;i++)
	{
    	for(j=0;j<col;j++)
			printf("  %d",arr[i][j]);
	printf("\n");
	}

return 0;
}
