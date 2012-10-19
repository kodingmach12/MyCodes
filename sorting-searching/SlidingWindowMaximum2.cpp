//Most optimal code using doubly ended queue
void maxSlidingWindow(int A[], int n, int w, int B[])
{
  deque<int> Q;
  for (int i = 0; i < w; i++) {
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  for (int i = w; i < n; i++) {
    B[i-w] = A[Q.front()];
    while (!Q.empty() && A[i] >= A[Q.back()])
      Q.pop_back();
    while (!Q.empty() && Q.front() <= i-w)
      Q.pop_front();
    Q.push_back(i);
  }
  B[n-w] = A[Q.front()];
}
//******************************************************************************
#define forall(i,a,b)   for(i=a;i<b;i++)
typedef pair<int,int> Pair;
void slidingWindowMaximum2(int a[],int n,int w,int b[])
{
    assert(n>0 && w>0 && w<=n);
    priority_queue<Pair> Q;
    int i,j;
    forall(i,0,w)
        Q.push(Pair(a[i],i));
  forall(i,w,n)
  {
    Pair p=Q.top();
    b[i-w]=p.first;
    while( p.second <= i-w )
    {
            Q.pop();
            p=Q.top();
    }
    Q.push(Pair(a[i],i));
  }
  b[n-w]=Q.top().first;
}


//*********************************************************************************

void slidingWindowMaxMin(int a[], int N, int W)
{
  printf("Maximum 	Minimum\n");
 deque<int> Qmax,Qmin;
  for (int i = 0; i < W; i++) {

    while (!Qmax.empty() && a[i] >= a[Qmax.back()])
      Qmax.pop_back();
    Qmax.push_back(i);

    while (!Qmin.empty() && a[i] <= a[Qmin.back()])
      Qmin.pop_back();
    Qmin.push_back(i);

  }
  for (int i = W; i < N; i++) {
	printf(" %d ",a[Qmax.front()]);
	printf(" %d \n",a[Qmin.front()]);
    while (!Qmax.empty() && a[i] >= a[Qmax.back()])
      Qmax.pop_back();
    while (!Qmax.empty() && Qmax.front() <= i-W)
      Qmax.pop_front();
    Qmax.push_back(i);

    while (!Qmin.empty() && a[i] <= a[Qmin.back()])
      Qmin.pop_back();
    while (!Qmin.empty() && Qmin.front() <= i-W)
      Qmin.pop_front();
    Qmin.push_back(i);

  }
	printf(" %d ",a[Qmax.front()]);
	printf(" %d \n",a[Qmin.front()]);
}
