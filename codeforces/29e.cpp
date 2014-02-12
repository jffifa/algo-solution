#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int INF = 0x1fffffff;

struct snode
{
	int u, v, p;
	snode() {}
	snode(int a, int b, int c): u(a), v(b), p(c) {}
};

int N, M;
int prev[503][503][2];
int dis[503][503][2];
vector<int> adj[503];
queue<snode> q;

int solve()
{
	int i, j, k;
	int u, v, p, nu, nv, np, nd;
	for (u = 1; u <= N; ++u)
		for (v = 1; v <= N; ++v)
			dis[u][v][0] = dis[u][v][1] = INF;
	dis[1][N][0] = 0; prev[1][N][0] = 0;
	q.push(snode(1, N, 0));
	while (!q.empty())
	{
		snode f = q.front(); q.pop();
		u = f.u; v = f.v; p = f.p; np = p^1;
		if (p == 0)
		{
			if (u==N && v==1) return dis[N][1][0];
			for (i = 0; i < adj[u].size(); ++i)
			{
				nu = adj[u][i]; nv = v;
				if (dis[nu][nv][np] != INF) continue;
				dis[nu][nv][np] = dis[u][v][p];
				prev[nu][nv][np] = u;
				q.push(snode(nu, nv, np));
			}
		}
		else
		{
			for (i = 0; i < adj[v].size(); ++i)
			{
				nu = u; nv = adj[v][i];
				if (dis[nu][nv][np] != INF) continue;
				if (nv == u) continue;
				dis[nu][nv][np] = dis[u][v][p]+1;
				prev[nu][nv][np] = v;
				q.push(snode(nu, nv, np));
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d%d", &N, &M);
	int hmr = M;
	int i, j, k;
	int u, v;
	while (hmr--)
	{
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = solve();
	if (ans >= 0)
	{
		printf("%d\n", ans);
		u = N; v = 1;
		vector<int> a, b;
		for (i = 0; i <= ans; ++i)
		{
			b.push_back(v);
			v = prev[u][v][0];
			a.push_back(u);
			u = prev[u][v][1];
		}
		reverse(a.begin(), a.end());
		for (i = 0; i <= ans; ++i)
		{
			if (i) putchar(' ');
			printf("%d", a[i]);
		}
		puts("");
		reverse(b.begin(), b.end());
		for (i = 0; i <= ans; ++i)
		{
			if (i) putchar(' ');
			printf("%d", b[i]);
		}
		puts("");
	}
	else
	{
		puts("-1");
	}
	return 0;
}

