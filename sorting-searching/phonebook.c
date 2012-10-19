/*
This file provides all the necessary functions
to implement a telephone directory. The telephone
directory keeps a record of first name, last name
and  the phone number of the person. The following
functions are provided to execute the phone book
operations
	1. Add
	2. Delete
	3. Edit
	4. Search
	5. List

The program starts with initialising the phonebook
data structure with entries from a given file.

-Kiran Anna
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* constants */
#define LNAMELEN	20   /* max size of the last name */
#define FNAMELEN	15   /* max size of the first name */
#define PHONELEN	12   /* max size of the phone number */
#define BOOKSIZE	100  /* max size of the telephone directory */

/* function names */
#define ADD		1
#define DEL		2
#define EDIT	3
#define SEARCH	4
#define LIST    5
#define QUIT	6

#define NOENTRY -1	/* if there is no entry present by the name asked for */

/* structure to describe the entries in the directory */
typedef struct {
	char lname[LNAMELEN];
	char fname[FNAMELEN];
	char phoneNo[PHONELEN];
}entry;


/* functions */
int readFile(char* fname,entry *phoneBook, int numOfEntries);
void writeFile(char* oldfname, entry *phoneBook, int numOfEntries);

int menu();
void run(int choice,entry *book,int *nEntry, int *changed);
void  add(entry *phoneBook, int *nEntry, int *changed);
void  del(entry *phoneBook, int *nEntry, int *changed);
void  edit(entry *phoneBook, int *nEntry, int *changed);
void search(entry *phoneBook, int bookSize);
void list(entry *phoneBook, int bookSize);
int findName(entry *phoneBook, char *name, int bookSize);


int main()
{
	char choice;				/* used for the menu choice */
	entry phoneBook[BOOKSIZE];  /* Telephone Directory      */
	char inputBook[32];			/* input file name for the directory */
	int bookModified = 0;		/* used to note any changes in the Telephone 
Directory */
	int numOfEntries = 0;		/* Used to point to the next empty slot as well as 
number of records */

	numOfEntries = readFile(inputBook, phoneBook, numOfEntries);
	printf("\n\nReading records from the book %s\n",inputBook);
	list(phoneBook, numOfEntries);

	do
	{
		printf("\n\n");
		choice = menu();
		run(choice,phoneBook,&numOfEntries,&bookModified);

	} while (choice != QUIT);

	if (bookModified)
		writeFile(inputBook, phoneBook, numOfEntries);

	return 0;
}

/*
This function reads the input phone book file name, opens the file
and intialises the array reprensenting phone book with the entries from
the file.
input: fname      = Input file name
	   phoneBook  = data structure for the phone book
	   count      = the current empty slot in the array as well as the
					number of records in the array.

output: returns current number of records in the array or the index of the
		next empty slot.the user selection
*/
int readFile(char* fname,entry *phoneBook, int count)
{
	FILE *fptr;

	printf("Please enter the name of the phoneBook: ");
	scanf("%s",fname);

	fptr = fopen(fname,"r");
	if (fptr == NULL)
	{
		printf("ERROR: phone book not found!\n");
		exit(0);
	}


	while(count < BOOKSIZE && fscanf(fptr,"%s %s %s",phoneBook[count].lname, 
phoneBook[count].fname, phoneBook[count].phoneNo) != EOF)
		++count;

	fclose(fptr);
	return count;
}

/*
This function reads the input phone book file name, opens the file
and intialises the array reprensenting phone book with the entries from
the file.
input: oldfname      = Intial Input file name
	   phoneBook     = data structure for the phone book
	   numOfEntries  = the current empty slot in the array as well as the
					   number of records in the array.

output: writes the current phone book in the array to a file specified by 
the user
		next empty slot.the user selection
*/
void writeFile(char* oldfname, entry *phoneBook, int numOfEntries)
{
	FILE *fptr;
	char newBook[32];
	int eof = 0;
	int index = 0;

	do {

		printf("Please enter the name of the new phoneBook: ");
		scanf("%s",newBook);
	} while(strcmp(oldfname,newBook) == 0);


	fptr = fopen(newBook,"w");
	if (fptr == NULL)
	{
		printf("ERROR: phone book not found!\n");
		exit(0);
	}


	while(index < numOfEntries) {
		fprintf(fptr,"%s %s %s\n",phoneBook[index].lname, phoneBook[index].fname, 
phoneBook[index].phoneNo);
		++index;
	}
	fclose(fptr);
}




/*
This function dispays the menu of all options
avaliable to the user and reads the user selection.
input: None
output: returns the user selection
*/
int menu()
{
	int choice;
	printf("\n************************************\n");
	printf("*    TELEPHONE DIRECTORY MENU      *\n");
	printf("************************************\n");
	printf("*  OPTIONS               CHOICE    *\n");
	printf("*   ADD                     1      *\n");
	printf("*   DEL                     2      *\n");
	printf("*   EDIT                    3      *\n");
	printf("*   SEARCH                  4      *\n");
	printf("*   LIST                    5      *\n");
	printf("*   QUIT                    6      *\n");
	printf("************************************\n");
	printf("\nPlease enter your Choice [1-6]: ");
	scanf("%d",&choice);
	fflush(stdin);
	return choice;
}


/* the function calls the respective function based on
   the choice selected by the user.
   input: int choice: user choice
		  entry *phoneBook: address to the phone Book
		  int *nEntry: first empty index in the phone book
		  int *changed: used to track any changes to the phone book
   output: None
*/
void run(int choice, entry *phoneBook, int* nEntry,int *changed)
{
	switch (choice)
	{

		case ADD:{
					add(phoneBook,nEntry,changed);
					break;
				 }

		case DEL:{
					del(phoneBook,nEntry,changed);
					break;
				 }
		case EDIT:{
					edit(phoneBook, nEntry,changed);
					break;
				  }
		case SEARCH:{
						search(phoneBook,*nEntry);
						break;
					}

		case LIST:{
					list(phoneBook,*nEntry);
					break;
				  }

		case QUIT: {
					 printf("\nclosing the telephone directory....\n\n");
					 break;
				   }
		default:printf("\n\nIllegal Input\n\n");
	 }
}

/* the function adds a new entry into the phoen book
   at the position indicated by nEntry. Before adding
   the entry, it checks if it is duplicate entry.
   input: entry *phoneBook: address to the phone Book
		  int *nEntry: first empty index in the phone book
   output: None
*/
void add(entry *phoneBook, int *nEntry, int *changed)
{

	char name[LNAMELEN];

	int dupEntry;
	int nextEntry = *nEntry;

	if (nextEntry == BOOKSIZE)
	{
		printf("The database is full");
		return;
	}

	printf("Enter Your Last Name (<%d): ",LNAMELEN);
	scanf("%s",name);

	dupEntry = findName(phoneBook,name,nextEntry);

	if (dupEntry == NOENTRY)
	{
		strcpy(phoneBook[nextEntry].lname,name);

		printf("Enter Your First Name (<%d): ",FNAMELEN);
		scanf("%s",phoneBook[nextEntry].fname);

		printf("Enter your phone no [xxxyyyzzzz] :");
		scanf("%s", phoneBook[nextEntry].phoneNo);
		(*changed) = 1;
		(*nEntry)++;

	}
	else
		printf("The name already exists");

}

/* the function deletes an entry given by the user from
   the phone book. the last entry is moved into the
   deleted entry's position.
   input: entry *phoneBook: address to the phone Book
		  int *nEntry: first empty index in the phone book
   output: None
*/
void del(entry *phoneBook, int *nEntry, int *changed)
{
	char name[LNAMELEN];
	int index;

	printf("Enter the last name to be deleted: ");
	scanf("%s",name);
	index = findName(phoneBook,name,(*nEntry));

	if (index != NOENTRY){
		strcpy(phoneBook[index].lname,phoneBook[(*nEntry)-1].lname);
		strcpy(phoneBook[index].fname,phoneBook[(*nEntry)-1].fname);
		strcpy(phoneBook[index].phoneNo,phoneBook[(*nEntry)-1].phoneNo);
		(*changed) = 1;
		(*nEntry)--;
		printf("\n%s is deleted\n",name);
	}
	else
	printf("The name is not in the Directory\n");
}

/* the function edits an entry given by the user.
   input: entry *phoneBook: address to the phone Book
		  int *nEntry: first empty index in the phone book
   output: None
*/
void edit(entry *phoneBook, int *nEntry, int *changed)
{

	int index;
	char name[LNAMELEN];


	printf("enter the name to be edited: ");
	scanf("%s",name);

	index = findName(phoneBook,name,(*nEntry));

	if (index!= NOENTRY)
	{
		printf("Enter the new number:  ");
		scanf("%s", phoneBook[index].phoneNo);
		(*changed) = 1;
	}
	else
		printf("%s is not in the Directory\n",name);
}


/* the function returns the index of an entry in the
   phone if present. otherwise, returns NOENTRY.
   input: entry *phoneBook: address to the phone Book
		  char* name: name of the entry to be looked for
		  int *nEntry: first empty index in the phone book
   output: None
*/
int findName(entry *phoneBook, char *name, int bookSize)
{
	int i;

	for (i=0;i < bookSize;i++)
	{
		if(!strcmp(phoneBook[i].lname,name))
			return i;
	}
	return NOENTRY;
}

/* the function searches for an entry requested by
   the user and prints all the details of that entry.
   phone if present. otherwise, returns NOENTRY.
   input: entry *phoneBook: address to the phone Book
		  int bookSize: current size of the phone Book
   output: None
*/
void search(entry *phoneBook, int bookSize)
{

	char name[LNAMELEN];
	int index;

	printf("Enter the name to be searched: ");
	scanf("%s",name);

	index=findName(phoneBook,name,bookSize);

	if(index != NOENTRY)
	{
		printf("\nNAME\t\tPH.NUM\t\tEMAIL\n");
		printf("%s\t\t%s\t\t%s\n",phoneBook[index].lname,phoneBook[index].fname,phoneBook[index].phoneNo);

	}
	else

		printf("The name %s is not found\n",name);
}


/* the function prints the complete details of all the entries
   in the phoen book.
   input: entry *phoneBook: address to the phone Book
		  int bookSize: the current size of the book
   output: None
*/
void list(entry *phoneBook, int bookSize)
{
	int i;

	printf("\nLAST NAME\tFIRST NAME\tPHONE NUMBER\n");

	for (i=0;i< bookSize;i++)
		printf("%s\t\t%s\t\t%s\n",phoneBook[i].lname,phoneBook[i].fname,phoneBook[i].phoneNo);
}





































































































































