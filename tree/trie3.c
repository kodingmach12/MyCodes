#include<stdio.h>
#include<malloc.h>
typedef struct trie
{
int words;
int prefixes;
struct trie* next[26];
}trie;

trie* createNode()
{
 trie* temp=(trie*)malloc(sizeof(trie));
 temp->words=0;
 temp->prefixes=0;
 int i=0;
 for(i=0;i<26;i++)
   temp->next[i]=NULL; 

return temp;
}

void addword(trie* root, char* word)
{
	if((*word)=='\0')
		return;
	char* temp=word;
	int c=0;
	while((*temp)!='\0')
	{	
	c=(*temp)-97; 
	if(root->next[c]==NULL)
		root->next[c]=createNode();
	root->next[c]->prefixes+=1;
	root=root->next[c];
	temp++;
	}	
root->words+=1;
}

int countwords(trie* root,char* word)
{
int cnt=0;
if((*word)=='\0')
	return cnt;
char* temp=word;
int c=0;
	while((*temp)!='\0')
	{	c=(*temp)-97;
	if(root->next[c]==NULL)
	{
	printf(" Word not found ");
		break;
	}
//	printf("%c",c);
	root=root->next[c];
	temp++;
	}
if((*temp)=='\0')
	return root->words;
return cnt;
}

int countprefixes(trie* root,char* str)
{
if((*str)=='\0')
	return 0;







}

int main()
{
trie *root=createNode();
char str[100];
int total=0;
scanf("%d",&total);
	while(total--)
	{
		scanf("%s",str);
		addword(root,str);
	}

printf("Enter word to search \n");
scanf("%s",str);
printf("Word : %s Instances : %d\n ",str,countwords(root,str));
return 0;
}
