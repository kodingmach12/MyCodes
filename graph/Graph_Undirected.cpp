#include<iostream>
#include<queue>
using namespace std;
#define NODES 128

    int N;                  // total number of vertices
    bool M[N][N];   // adjacency matrix
    bool visited[N];

    void bfs(int s)
    {
        queue<int> Q;           // queue used for storing nodes
        s=0;                // source vertex
        for(int v=0;v<N;v++)
            visited[v]=false ;        // initialise visited array
        visited[s]=true;
        //  call function for this node
        //  DoColouring(s,somecolour);
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            for(int v=0;v<N;v++)
                if(!visited[v] && M[u][v])
                {
                    visited[v]=true;
                    // Docolouring(v,someColour);
                    Q.push(v);
                }
        }
    }
    void dfsUtil(int s)
    {
        if(visited[s])
            return;
        visited[s]=true;
        // Do some work on the node
        cout<<" "<<s;
        for(int v=0;v<N;v++)
            if(M[s][v])
                dfsUtil(v);
    }
    void dfs(int source)
    {
        for(int v=0;v<N;v++)
            visited[v]=false;
        dfsUtil(source);
    }
int main()
{
    scanf("%d",&N);


}
