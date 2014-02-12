#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x1fffffff;

struct sadj
{
	int id, v;
	sadj() {}
	sadj(int a, int b): id(a), v(b) {}
};

int N, M, s, t, x, y;
int hmr[1010][2];
vector<sadj> adj[2020];
int PREV[2020];
int dis[2020];

void bfs(int s)
{
	int i, j, u, v;
	for (u = 1; u <= 2000; ++u)
		dis[u] = INF;
	PREV[s] = dis[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (i = 0; i < adj[u].size(); ++i)
		{
			v = adj[u][i].v;
			if (dis[v]==INF)
			{
				dis[v] = dis[u]+1;
				PREV[v] = adj[u][i].id;
				q.push(v);
			}
		}
	}
}

int main()
{
	int i, j, k, u, v;
	scanf("%d", &M);
	for (i = 0; i < M; ++i)
	{
		scanf("%d%d", &u, &v);
		hmr[i+1][0] = u, hmr[i+1][1] = v;
		adj[v].push_back(sadj(i+1, u));
	}
	scanf("%d%d%d", &s, &x, &y);
	bfs(s);
	if (dis[x]==INF && dis[y]==INF) puts("IMPOSSIBLE");
	else
	{
		t = dis[x]<dis[y]?x:y;
		printf("%d\n", dis[t]);
		v = t;
		while (PREV[v])
		{
			printf("%d\n", PREV[v]);
			v = hmr[PREV[v]][1];
		}
	}
	return 0;
}
