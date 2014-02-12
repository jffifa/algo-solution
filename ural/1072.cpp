#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned int UI;

UI addr()
{
	UI res, x; char ch;
	for (int i = 0; i < 4; ++i)
	{
		scanf("%u%c", &x, &ch);
		res = (res<<8)|x;
	}
	return res;
}
UI mask()
{
	UI ip = addr();
	UI sm = addr();
	return ip & sm;
}

const int INF = 0x1fffffff;

vector<UI> ni[100];
vector<int> adj[100];
int dis[100], PREV[100];
int N, K, s, t;

void bfs(int s)
{
	int i, j, u, v;
	for (u = 1; u <= N; ++u)
		dis[u] = INF;
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (i = 0; i < adj[u].size(); ++i)
		{
			v = adj[u][i];
			if (dis[v] == INF)
			{
				dis[v] = dis[u]+1;
				PREV[v] = u;
				q.push(v);
			}
		}
	}
}

int main()
{
	int i, j, k, u, v;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		scanf("%d", &K);
		while (K--)
		{
			UI now = mask();
			ni[i].push_back(now);
		}
	}
	scanf("%d%d", &s, &t);
	for (i = 1; i <= N; ++i)
		for (j = i+1; j <= N; ++j)
			for (int p = 0; p < ni[i].size(); ++p)
				for (int q = 0; q < ni[j].size(); ++q)
				{
					if (ni[i][p] == ni[j][q])
					{
						adj[i].push_back(j);
						adj[j].push_back(i);
					}
				}
	bfs(s);
	if (dis[t] == INF)
		puts("No");
	else
	{
		puts("Yes");
		vector<int> path;
		v = t;
		while (v)
		{
			path.push_back(v);
			v = PREV[v];
		}
		reverse(path.begin(), path.end());
		for (i = 0; i < path.size(); ++i)
		{
			if (i) putchar(' ');
			printf("%d", path[i]);
		}
	}
	return 0;
}
