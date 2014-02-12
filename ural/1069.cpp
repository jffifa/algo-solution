#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[7777];

inline void ae(int u, int v)
{adj[u].push_back(v);}

int N;
int s[7777];
int last[7777];
set<int> h;

int main()
{
	int i, j, u, v;
	memset(last, 255, sizeof(last));
	while (~scanf("%d", &u))
	{
		s[N] = u;
		last[u] = N++;
	}
	for (u = 1; u <= N; ++u)
		if (last[u]==-1) h.insert(u);
	for (i = 0; i < N; ++i)
	{
		u = s[i];
		v = *h.begin();
		ae(u, v); ae(v, u);
		h.erase(v);
		if (i==last[u]) h.insert(u);
	}
	for (u = 1; u <= N+1; ++u)
	{
		sort(adj[u].begin(), adj[u].end());
		printf("%d:", u);
		for (i = 0; i < adj[u].size(); ++i)
			printf(" %d", adj[u][i]);
		puts("");
	}
	return 0;
}
