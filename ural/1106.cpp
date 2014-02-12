#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N;
bool vis[110], grp[110];
vector<int> adj[110];
vector<int> ans;

void bfs(int s)
{
	int u, v, i, j;
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	grp[s] = 0;
	while (!q.empty())
	{
		u = q.front(); q.pop();
		for (i = 0; i < adj[u].size(); ++i)
		{
			v = adj[u][i];
			if (!vis[v])
			{
				vis[v] = 1;
				grp[v] = !grp[u];
				q.push(v);
			}
		}
	}
}

int main()
{
	int i, j, k, u, v;
	scanf("%d", &N);
	for (u = 1; u <= N; ++u)
		while (scanf("%d", &v), v)
			adj[u].push_back(v);
	for (u = 1; u <= N; ++u)
		if (!vis[u]) bfs(u);
	for (u = 1; u <= N; ++u)
		if (grp[u]) ans.push_back(u);
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
