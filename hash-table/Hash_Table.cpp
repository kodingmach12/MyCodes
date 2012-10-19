#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define LF 20
#define forall(i,a,b)   for(i=a;i<b;i++)

typedef struct ListNode
{   int key;
    int data;
    struct ListNode *next;
}Lnode;

typedef struct HashTableNode
{
    int bcount;
    struct Lnode *next;
}HTnode;

typedef struct HashTable
{
    int tsize;
    int count;
    struct HTnode **table;
}HT;

HT* createHashTable(int size)
{
    HT *h;
    h=(HT*)malloc(sizeof(HT));
    if(!h)  return NULL;
    h->tsize = size/LF;
    h->count = 0;
    h->table = (HTnode**)malloc(sizeof(HTnode*)*h->tsize);
    if(!h->table)
    {
        cout<<" Memory Error "<<endl;
        free(h);
        return NULL;
    }
    int i;
    forall(i,0,h->tsize)
    {
        h->table[i]->next=NULL;
        h->table[i]->count=0;
    }
return h;
}
bool HashSearch(HT *h, int data)
{
    Lnode *temp;
    temp= h->table[ Hash(data,h->tsize) ]->next;        // Hash is a built-in function
    while(temp)
    {
        if(temp->data == data)
            return true;
        temp=temp->next;
    }
return false;
}
int HashInsert(HT *h, int data)
{
    int index;
    Lnode *temp,*newNode;
    if(HashSearch(h,data))
        return 0;
    index = Hash(data,h->tsize);
    temp = h->Table[index]->next;
    newNode = (Lnode*)malloc( sizeof(Lnode) );
    if(!newNode)
    {
        cout<<" out of space :( ";
        return -1;
    }
    newNode->key=index;
    newNode->data=data;
    newNode->next=h->table[index]->next;
    h->table[index]->next = newNode;
    h->table[index]->bcount++;
    h->count++;
    if( h->count/h->tsize > LF)
        Rehash(h);
return 1;
}
int HashDelete(HT *h, int data)
{
    if(!h)  return 0;
    int index;
    index = Hash(data,h->tsize);
    Lnode *temp;
    temp=h->table[index]->next;
    if(temp->data == data)
    {
        h->table[index]->next = temp->next;
        free(temp);
        h->table[index]->bcount--;
        h->count--;
        return 1;
    }
    Lnode *prev=NULL;
    while(temp)
    {
    if(temp->data == data)
    {
        pre->next=temp->next;
        free(temp);
        h->table[index]->bcount--;
        h->count--;
        return 1;
    }
        prev=temp;
        temp=temp->next;
    }
return 0;
}
