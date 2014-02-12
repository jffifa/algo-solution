#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, S;
vector<int> adj[1010];
vector<int> path;

void dfs(int u)
{
	while (adj[u].size())
	{
		int v = adj[u].back();
		adj[u].pop_back();
		dfs(v);
	}
	path.push_back(u);
}

int main()
{
	int u, v, d;
	scanf("%d%d", &N, &S);
	for (u = 1; u <= N; ++u)
		for (v = 1; v <= N; ++v)
		{
			scanf("%d", &d);
			if (u!=v && d==0)
				adj[u].push_back(v);
		}
	dfs(S);
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size()-1; ++i)
		printf("%d %d\n", path[i], path[i+1]);
	return 0;
}
