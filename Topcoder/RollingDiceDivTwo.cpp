#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class RollingDiceDivTwo {
	public:
	int partition(string arr,int low,int high)
{
	int pivot,temp,down=low,up=high;
	pivot=arr[low];
	while(down<up)
	{
		while(arr[down]<=pivot && down<high)
			down++;
		while(arr[up]>pivot)
			up--;
		if(down<up)
		{	temp=arr[down];
			arr[down]=arr[up];
			arr[up]=temp;
		}
	}
	arr[low]=arr[up];
	arr[up]=pivot;
	return up;
}
void qsort(string s,int low,int high)
{
	int pos;
	if(low>=high)
		return;
	pos=partition(arr,low,high);
		qsort(arr,low,pos-1);
		qsort(arr,pos+1,high);
}
	int minimumFaces(vector <string> rolls)
	{
    int total=rolls.size();
    int elems=rolls[0].size(),res=0,min=0,i,j;
    string s;
    int n;

    for(i=0;i<total;i++)
        qsort(rolls[i],0,elems);

    for(i=0;i<elems;i++)
    {
    min=0;
    for(j=0;j<total;j++)
        if(min>rolls[j][i])
            min=rolls[j][i];
    res+=min;
    }
    return res;
}
};
int main(void)
{
    RollingDiceDivTwo A;
    vector<string> rolls;
    string roll;
    int sz;
    cin>>sz;
    while(sz--)
    {
        cin>>roll;
        rolls.push_back(roll);
    }
    cout<<A.minimumFaces(rolls);
}
