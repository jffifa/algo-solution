#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int f[1010];
vector<int> adj[1010];
char s[2];

int dfs(int v, bool p)
{
	//printf("%d %d\n", v, p);
	if (adj[v].size()==0) return f[v];
	int t = 1, m = -10;
	if (p) t = -1;
	for (int i = 0; i < adj[v].size(); ++i)
		m = max(m, t*dfs(adj[v][i], !p));
	m *= t;
	return f[v] = m;
}

int main()
{
	int i, j, u, v;
	scanf("%d", &N);
	for (i = 2; i <= N; ++i)
	{
		scanf("%s%d", s, &u);
		adj[u].push_back(i);
		if (s[0]=='L') scanf("%d", f+i);
	}
	int ans = dfs(1, 0);
	if (ans==1) puts("+1");
	else printf("%d\n", ans);
	return 0;
}
