#include<iostream>
#include<queue>
using namespace std;
#define NODES 128

class Graph_Undirected{
public:
    int n;                  // total number of vertices
    bool M[n][n];   // adjacency matrix
    bool visited[n];

    void bfs(int s)
    {
        queue<int> Q;           // queue used for storing nodes
        s=0;                // source vertex
        for(int v=0;v<n;v++)
            visited[v]=false ;        // initialise visited array
        visited[s]=true;
        //  call function for this node
        //  DoColouring(s,somecolour);
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            for(int v=0;v<n;v++)
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
        for(int v=0;v<n;v++)
            if(M[s][v])
                dfsUtil(v);
    }
    void dfs()
    {
        for(int v=0;v<n;v++)
            visited[v]=false;
        int source=0;
        dfsUtil(source);
    }
};
