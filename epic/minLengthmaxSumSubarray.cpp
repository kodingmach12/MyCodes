#include<iostream>

/*	Test Cases:
all neg
all  pos
all 0
mix variants
*/
using namespace std;
void minLengthmaxSumSubarray( ){
	int arr[100];
	int size;
	cin >> size;
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}

	//Main Logic
	int curStart = 0,
	maxStart = 0,
	curSum = 0,
	maxSum = arr[0],
	maxLen = 1;

	for(int i=0;i<size;i++){
		curSum+=arr[i];
		if(curSum > maxSum){
			maxSum = curSum;
			maxStart = curStart;
		}else if(curSum == maxSum && maxLen > (i-curStart+1) ){
			maxStart = curStart;
		}
		if(curSum<=0){
			curSum = 0;
			curStart = i+1;
		}
	}
	printf("Max Sum Subarray starts at %d and max Sum is %d\n",maxStart,maxSum);
}
int main(){
	int tcase;
	cin>>tcase;
	for(int i=0;i<tcase;i++){
		minLengthmaxSumSubarray();
	}
	return 0;
}