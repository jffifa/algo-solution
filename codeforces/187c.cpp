#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct se
{
	int v, next;
}e[404000];

int N, M, K;
int s, t;
int E;
int d[100010];
int fst[100010];
bool inq[100010];
bool flag[100010];

void ae(int u, int v)
{
	e[E].v = v;
	e[E].next = fst[u];
	fst[u] = E++;
}

bool spfa(int lim)
{
	int i, u, v;
	int rest;
	memset(d, 0, sizeof(d));
	memset(inq, 0, sizeof(inq));
	queue<int> q;
	d[s] = lim;
	q.push(s);
	inq[s] = 1;
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		inq[u] = 0;
		for (i = fst[u]; i != -1; i = e[i].next)
		{
			v = e[i].v;
			if (v==t) return 1;
			rest = flag[v]?lim:d[u]-1;
			if (rest > d[v])
			{
				d[v] = rest;
				if (!inq[v] && d[v])
				{
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, k, u, v;
	cin>>N>>M>>K;
	for (k = 0; k < K; ++k)
	{
		scanf("%d", &i);
		flag[i] = 1;
	}
	memset(fst, -1, sizeof(fst));
	while (M--)
	{
		scanf("%d%d", &u, &v);
		ae(u, v); ae(v, u);
	}
	cin>>s>>t;
	int l=1, r=N, m;
	while (l < r)
	{
		m = l+r>>1;
		if (spfa(m)) r = m;
		else l = m+1;
	}
	if (r==N) cout<<-1<<endl;
	else cout<<r<<endl;
	return 0;
}
