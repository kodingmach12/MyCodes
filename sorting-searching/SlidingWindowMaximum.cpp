#include<iostream>

using namespace std;
typedef pair<int, int> Pair;
void maxSlidingWindow(int A[], int n, int w, int B[]) {
  priority_queue<Pair> Q;
  for (int i = 0; i < w; i++)
    Q.push(Pair(A[i], i));
  for (int i = w; i < n; i++) {
    Pair p = Q.top();
    B[i-w] = p.first;
    while (p.second <= i-w) {
      Q.pop();
      p = Q.top();
    }
    Q.push(Pair(A[i], i));
  }
  B[n-w] = Q.top().first;
}
void main(void)
{
    int i,n,w,A[n],B[w];
    cin>>n>>w;

    i=0;
    while(i<n)
    {   i++;
        cin>>A[i];
    }
    maxSlidingWindow(A,n,w,B);
    i=0;
    while(i<w)
        cout<<" "<<B[i++];
}
