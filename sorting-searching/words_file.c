#include<stdio.h>
int tot_words(FILE *fp)
{
int wrd=0,flg=0;
char c;

	while( (c=fgetc(fp))!=EOF )
	{
		printf("%c",c);
		if(c==' ' || c=='\t' || c=='\n')
			flg=0;
		else if(flg==0)
		{
		wrd++;
		//printf("\n-->\n");
		flg=1;
		}
	}
return wrd;
}
int main()
{
FILE *fp;
fp=fopen("dangerous.c","r+");
printf("\n\nThe total words in the file are %d",tot_words(fp) );
return 0;
}