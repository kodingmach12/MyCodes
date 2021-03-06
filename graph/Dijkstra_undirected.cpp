#include<iostream>
#include<queue>
using namespace std;

int graph[250][250], n; // -1  means "no edge"
int dist[250];
bool done[250];

void dijkstra( int s ) {
    for( int i = 0; i < n; i++ ) {
    dist[i] = INT_MAX;
    done[i] = false;
    }
    dist[s] = 0;
    while( true ) {
        // find the vertex with the smallest dist[] value
        int u = 1,
        bestDist = INT_MAX;
        for( int i = 0; i < n; i++ )
            if( !done[i] && dist[i] < bestDist ) {
                u = i;
                bestDist = dist[i];
            }
        if( bestDist == INT_MAX ) break;
        // relax neighbouring edges
        for( int v = 0; v < n; v++ )
            if( !done[v] && graph[u][v] != 1) {
            if( dist[v] > dist[u] + graph[u][v] )
            dist[v] = dist[u] + graph[u][v];
            }
        done[u] = true;
    }
}
int shortestpath(int u, int v)
{
    dijkstra(u);
    return dist[v];
}
void solve()
{
    int S,G,D;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>S>>G>>D;
        cout<<shortestpath(S,G);
        cout<<shortestpath(G,D);
        cout<<shortestpath(S,D);
    }
}
int main()
{
    solve();
return 0;
}
