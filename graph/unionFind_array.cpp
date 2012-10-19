#include<cstdio>
#include<iostream>

using namespace std;
int main()
{
    int N,S;
    cout << " Enter the no. of elements " << endl;
    cin >> N;
    int* arr = new int[N];
    cout << "Enter the no. of stepes" << endl;
    cin >> S;
    int p,q,t;
    for(int i=0;i<N;i++){
        arr[i]=i;
    }
    while(S--){
        cin >>  p >> q ;
        t = arr[p];
        if(t == arr[q]) continue;
        for(int i=0; i<N; i++)
        {
            if(t==arr[i])   arr[i]=arr[q];
        }
        cout <<" \t "<< p << " " << q <<endl;
    }
return 0;
}
