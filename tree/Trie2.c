#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define s(n) scanf("%d",&n)
#define ss(n) scanf("%s",n)

#define p(n) printf("%d\n",n)
#define ps(n) printf("%s\n",n)


typedef struct trie
{
int prefixes;
struct trie* next[26];
}trie;

trie* createNode()
{
 trie* temp=(trie*)malloc(sizeof(trie));
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
}

int countwords(trie* root,char* word){
    int cnt=0,c=0;
	if((*word)=='\0')
		return cnt;
	while((*word)!='\0'){
		c=(*word)-97;
		if(root->next[c]==NULL){
            printf(" Word not found ");
			break;
		}
		root=root->next[c];
		word++;
	}
    int tmp1=root->prefixes;
	if((*word)=='\0'){
	int i=0,tmp2=0;
		for(i=0;i<26;i++){
		if(root->next[i])
		  tmp2+=root->next[i]->prefixes;
		}
	return tmp1-tmp2;
	}
return cnt;
}

int countprefixes(trie* root,char* str)
{
if((*str)=='\0')
	return 0;
}

void removeword(trie* root,char* word)
{
	if(countwords(root,word)==0)
	{
	  printf("Word not found in dictionary\n");
	  return;
	}
	int c=0;
	while(*word)
	{
	c=(*word)-'a';
   	if(root->next[c]==NULL)
   	{
		break;
   	}
	root->next[c]->prefixes--;
	root=root->next[c];
	}
}
int main()
{
trie *root=createNode();
char str[100];
int total=0;
s(total);
	while(total--)
	{
		scanf("%s",str);
		addword(root,str);
	}

printf("Enter word to search \n");
ss(str);
printf("Word : %s Instances : %d\n ",str,countwords(root,str));
printf("ENter word to remove\t");
ss(str);
removeword(root,str);

printf("Enter word to search \n");
ss(str);
printf("Word : %s Instances : %d\n ",str,countwords(root,str));



return 0;

}
