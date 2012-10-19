#include<stdio.h>
#include<string.h>

/*
    Navin is a good and a bad boy but loves a good girl
*/
int findcount(char *line,char *word)
{
char *t1=line,*t2=word;
int cnt=0;
printf("\n%s\n%s\n",t1,t2);
	while(*t1!='\0')
	{
		if(*t1==*t2)
		{
			//printf("Matched");
			//int cnt1=0;
			while(*t1==*t2)
			{
				cnt1++;
				t1++;
				t2++;
			}
			//printf("	%d	",cnt1);
			if(*t1==' ')
				cnt++;
			if(*t1=='\0' && *t2=='\0')
				cnt++;
		t2=word;

		}

	t1++;
	}
	return cnt;
}

int main()
{
char line[100],word[10];
gets(line);
printf("%s\nEnter word to find   --  ",line);
gets(word);
printf("\ncount :- %d\n",findcount(line,word));
return 0;
}
