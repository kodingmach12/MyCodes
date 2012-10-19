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
    int i,j,icnt,jcnt;
    while(S--){
        cin >>  p >> q ;
        for( i=p,icnt=1; i!=arr[i]; i=arr[i],icnt++ );
        for( j=q,jcnt=1; j!=arr[j]; j=arr[j],jcnt++ );
        if(i==j)    continue;
        if(icnt <= jcnt)
            arr[i]=arr[j];
        else
            arr[j]=arr[i];
        cout <<" \t "<< p << " " << q <<endl;
    }
return 0;
}
