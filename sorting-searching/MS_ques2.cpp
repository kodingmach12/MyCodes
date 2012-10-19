void func(int arr[], int n)
{
    assert(n>0);
    if(n<=2)    return;
    int swap[2]={0};
    int start=1,end=n-2;    // 0-based array
    swap[0]=arr[n/2];
    swap[1]=arr[n/2+1];
    while(start<=end)
    {
        swap(arr[start],swap[1]);
        start++;
        swap(arr[end],swap[0]);
        end--;
    }
}
