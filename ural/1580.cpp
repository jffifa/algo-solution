//ural1580
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1001;
const double EPS = 1e-8;

int N, M;
double s[MAXN][MAXN];
vector<int> adj[MAXN];
double x[MAXN], b[MAXN];
int k[MAXN];
int st;
bool sol[MAXN];
bool ok;

void dfs(int u)
{
	int v;
	for (int i = 0; i < adj[u].size() && !sol[st]; ++i)
	{
		v = adj[u][i];
		if (k[v]==k[u])
		{
			sol[st] = 1;
			x[st] = (s[u][v]-b[u]-b[v])/(double)(k[u]+k[v]);
			return;
		}
		if (!k[v])
		{
			k[v] = -k[u]; b[v] = -b[u]+s[u][v];
			dfs(v);
		}
	}
}

void check(int u)
{
	int v;
	for (int i = 0; i < adj[u].size() && ok; ++i)
	{
		v = adj[u][i];
		if (sol[v])
		{
			if (fabs(x[u]+x[v]-s[u][v])>EPS)
			{
				ok = 0;
				return;
			}
		}
		else
		{
			sol[v] = 1;
			x[v] = s[u][v]-x[u];
			check(v);
		}
	}
}

bool solve()
{
	memset(k, 0, sizeof(k));
	memset(sol, 0, sizeof(sol));
	for (int u = 1; u <= N; ++u)
		if (!sol[u])
		{
			k[u] = 1; b[u] = 0;
			st = u;
			dfs(u);
			if (!sol[u]) return 0;
			ok = 1;
			check(st);
			if (!ok) return 0;
		}
	return 1;
}

int main()
{
	int u, v, d;
	scanf("%d%d", &N, &M);
	while (M--)
	{
		scanf("%d%d%d", &u, &v, &d);
		adj[u].push_back(v);
		adj[v].push_back(u);
		s[u][v] = s[v][u] = d;
	}
	if (solve())
	{
		for (u = 1; u <= N; ++u)
			printf("%.2f\n", x[u]);
	}
	else
		puts("IMPOSSIBLE");
	return 0;
}

