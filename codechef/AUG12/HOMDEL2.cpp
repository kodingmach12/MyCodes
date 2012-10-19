#include<iostream>
#include<queue>
//#define INT_MAX 10000000
#include<limits.h>
using namespace std;
int graph[250][250],n; // -1  means "no edge"
int shortest[250][250];
int dist[250];
bool done[250];
bool found[250];

void floydWarshall() {
for( int k = 0; k < n; k++ )
for( int i = 0; i < n; i++ )
for( int j = 0; j < n; j++ )
    graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j] );
}

void solve()
{
    int S,G,D;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
            shortest[i][j]=graph[i][j];
        }
    found[i] = false;
    }
    int M;
    cin>>M;
    floydWarshall();
    for(int i=0;i<M;i++)
    {
        cin>>S>>G>>D;
            //if(!found[S])   { dijkstra(S); found[S]=true; }
            //if(!found[G])   { dijkstra(G); found[G]=true; }

        //int a = shortest[S][G], b = shortest[G][D],c = shortest[S][D];
        int a = graph[S][G], b = graph[G][D],c = graph[S][D];
        int tot = a + b , save = tot - c;
        cout <<tot<<" "<<save<<endl;
    }
}
int main()
{
    solve();
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<"Shortest Path"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<shortest[i][j]<<" ";
        cout<<endl;
    }
    */
return 0;
}


