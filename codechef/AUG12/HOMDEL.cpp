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

void dij( int s ){
    for( int i = 0; i < n; i++ ){
        dist[i] = INT_MAX;
        done[i] = false;
    }
    dist[s] = 0;
    while( true ) {
        // find the vertex with the smallest dist[] value
        int u = 1,bestDist = INT_MAX;
        for( int i = 0; i < n; i++ )
            if( !done[i] && dist[i] < bestDist ) {
                u = i;
                bestDist = dist[i];
            }
        if( bestDist == INT_MAX ) break;
        // relax neighbouring edges
        for( int v = 0; v < n; v++ )
            if( !done[v] && graph[u][v]) {
                if( dist[v] > dist[u] + graph[u][v] )
                dist[v] = dist[u] + graph[u][v];
            }
        done[u] = true;
    }
}

void dijkstra(int s)
{
    dij(s);
    for(int i=0;i<n;i++)
        shortest[s][i]=dist[i];
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
    for(int i=0;i<M;i++)
    {
        cin>>S>>G>>D;
        if(!found[S])   { dijkstra(S); found[S]=true; }
        if(!found[G])   { dijkstra(G); found[G]=true; }

        int a = shortest[S][G], b = shortest[G][D],c = shortest[S][D];
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

