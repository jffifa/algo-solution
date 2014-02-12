#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int st;
int ord[200001], scc[100001], scccnt;
vector<int> adj[100001];
vector<int> radj[100001];
char vis[100001];
int cnt;
stack<int> stkdfs;
stack<int> stkrdfs;
int now[100001];

void dfs(int s)
{
	stkdfs.push(s);
	vis[s] = 1;
	while (!stkdfs.empty())
	{
		int u = stkdfs.top();
		//printf("##%d %d\n", hmr, now[hmr]);
		if (now[u]==adj[u].size())
		{
			ord[++cnt] = u;
			stkdfs.pop();
			continue;
		}
		int v = adj[u][now[u]];
		if (!vis[v])
		{
			stkdfs.push(v);
			vis[v] = 1;
		}
		now[u]++;
	}
	/*
	for (int i = 0; i < adj[u].size(); ++i)
		if (!vis[adj[u][i]]) dfs(adj[u][i]);
	ord[++cnt] = u;
	*/	
}

void rdfs(int s)
{
	stkrdfs.push(s);
	vis[s] = 1;
	scc[s] = scccnt;
	while (!stkrdfs.empty())
	{
		int u = stkrdfs.top();
		if (now[u]==radj[u].size())
		{
			stkrdfs.pop();
			continue;
		}
		int v = radj[u][now[u]];
		if (!vis[v])
		{
			stkrdfs.push(v);
			vis[v] = 1;
			scc[v] = scccnt;
		}
		now[u]++;
	}
	/*
	vis[u] = 1;
	scc[u] = scccnt;
	for (int i = 0; i < radj[u].size(); ++i)
		if (!vis[radj[u][i]]) rdfs(radj[u][i]);
	*/
}

int N;

void korasaju()
{
	cnt = 0;
	memset(vis, 0, sizeof(vis));
	memset(now, 0, sizeof(now));
	for (int u = 1; u <= N; ++u)
		if (!vis[u]) dfs(u);
	//puts("ok");
	scccnt = 0;
	memset(vis, 0, sizeof(vis));
	memset(now, 0, sizeof(now));
	for (int i = N; i >= 1; --i)
		if (!vis[ord[i]]) {++scccnt; rdfs(ord[i]);}
}

int v;

int main()
{
	scanf("%d", &N);
	for (int u = 1; u <= N; ++u)
	{
		scanf("%d", &v);
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	korasaju();
	//puts("ok");
	int ans1=0, ans2=0;
	cnt = 0;
	ans2 = scccnt;
	memset(vis, 0, sizeof(vis));
	memset(now, 0, sizeof(now));
	for (int u = 1; u <= N; ++u)
		if (!vis[u] && radj[u].size()==0)
		{
			++ans1;
			dfs(u);
		}
	for (int u = 1; u <= N; ++u)
		if (!vis[u])
		{
			++ans1;
			dfs(u);
		}
	printf("%d %d\n", ans1, ans2);
	//printf("%d %d\n", cntr+cntch, cntr+cntchv);
	return 0;
}
