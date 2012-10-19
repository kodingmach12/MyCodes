#include <iostream>
#include <string.h>
using namespace std;

int source, dest;
int ans[1024];
int mat[1024][1024];
int n, m;

int dfs(int u)
{
	if(u == dest)
		return 1;

	if(ans[u] != -1)
		return ans[u];

	ans[u] = 0;
	for(int i = 0; i < n; i ++)
		if(mat[u][i] == 1)
			ans[u] += dfs(i);
	return ans[u];
}

int main()
{
	memset(mat, 0, sizeof mat);
	memset(ans, -1, sizeof ans);

	cin >> n >> m; // number of nodes and edges
	while(m --)
	{
		int a, b;
		cin >> a >> b;
		mat[a][b] = 1;
	}

	cin >> source >> dest;
	cout << dfs(source) << endl;

	return 0;
}
