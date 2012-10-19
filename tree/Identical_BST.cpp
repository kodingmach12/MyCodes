#include<iostream>
using namespace std;
void print(int arr[],int size)
{
    int i=0;
    for(i=0;i<size;i++)
        cout<<" "<<arr[i];
    cout<<endl;
}
int partition(int arr[],int low,int high)
{
	int pivot,temp,down=low,up=high-1;
	pivot=arr[low];
	while(down<up)
	{
		while(arr[down]<=pivot && down<high)
			down++;
		while(arr[up]>pivot)
			up--;
			//printf("\ndown:%d   up:%d\n",down,up);
		if(down<up)
		{	temp=arr[down];
			arr[down]=arr[up];
			arr[up]=temp;
		}
        //print(arr,high);
	}
	arr[low]=arr[up];
	arr[up]=pivot;
return up;
}

int  checkidenticaltree(int a[],int  b[],int lena,int lenb)
{
   if (lena!= lenb)
       return 0;
   if (a[0] != b[0])
       return 0;
   if (lena <= 1)
       return 1;
int i=0,j=0,k=0,alen1=0,alen2=0,blen1=0,blen2=0,x=0;
int a1[lena],a2[lena],b1[lenb],b2[lenb];

   for(i=1;i<lena;i++)
    {
        x=a[i];
        if( x < a[0])
           a1[j++]=x;
       else
           a2[k++]=x;

    }
    alen1=j;
    alen2=k;


   for(i=1,j=0,k=0;i<lenb;i++)
    {
        x=b[i];
        if( x < b[0])
           b1[j++]=x;
       else
           b2[k++]=x;

    }
    blen1=j;
    blen2=k;

//printf("\nalen1:%d alen2:%d   blen1:%d blen2:%d\n",alen1,alen2,blen1,blen2);
return (checkidenticaltree(a1,b1,alen1,blen1) &&checkidenticaltree(a2,b2,alen2,blen2));
}

int main()
{
int arr1[]={15,20,10,5,30,12};
int size=(sizeof(arr1)/sizeof(arr1[0]));
int arr2[]={15,10,12,20,30,15};
print(arr1,size);
print(arr2,size);

if(checkidenticaltree(arr1,arr2,size,size))
  cout<<" same "<<endl;
else
    cout<<" Not same "<<endl;
}



