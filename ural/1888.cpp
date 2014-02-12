#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int ent, N, M, ANS;
int mat[100][100], color[100], aval[100], xv[100];
bool used[100], nos;
vector<int> sts;

void rbfs(int x);
void dfs(int x);
void bfs(int x);

int main()
{
	int i, j, k, x, y;
	nos = false;
	ANS = -1;
	scanf("%d%d", &M, &N);
	memset(used, 0, sizeof(used));
	memset(color, 0, sizeof(color));
	memset(mat, 0, sizeof(mat));
	for (i = 0; i < M; ++i)
	{
		scanf("%d%d", &x, &y);
		mat[x][y] = mat[y][x] = 1;
	}
	for (i = 1; i <= N; ++i)
	{
		if (!used[i])
		{
			color[i] = 1;
			sts.push_back(i);
			++ent;
			dfs(i);
		}
	}
	if (nos)
		puts("-1");
	else if (ent > 1)
	{
		puts("49");
		bfs(1);
		for (i = 1; i < sts.size(); ++i)
			rbfs(sts[i]);
		for (i = 1; i <= N; ++i)
			printf("%d ", xv[i]);
		puts("");
	}
	else
	{
		for (i = 1; i <= N; ++i)
			bfs(i);
		printf("%d\n", ANS);
		for (i = 1; i <= N; ++i)
			printf("%d ", aval[i]);
		puts("");
	}
	return 0;
}

void dfs(int x)
{
	if (nos) return;
	used[x] = true;
	int i, nc = 3 - color[x];
	for (i = 1; i <= N; ++i)
	{
		if (mat[x][i])
		{
			if (color[i] == 0)
				color[i] = nc;
			if (color[i] != nc)
			{
				nos = true;
				return;
			}
			if (!used[i])
				dfs(i);
		}
	}
}

void bfs(int x)
{
	int i, j, tm = -1, val[100];
	memset(val, 0, sizeof(val));
	val[x] = xv[x] = 1;
	queue<int> q;
	q.push(x);
	bool inq[100];
	memset(inq, 0, sizeof(inq));
	while (!q.empty())
	{
		int fid = q.front();
		q.pop();
		for (i = 1; i <= N; ++i)
		{
			if (mat[fid][i] && val[i] == 0)
			{
				val[i] = val[fid] + 1;
				xv[i] = val[i];
				q.push(i);
			}
		}
	}
	for (i = 1; i <= N; ++i)
		tm = max(tm, val[i]);
	if (ANS < tm - 1)
	{
		ANS = tm - 1;
		for (i = 1; i <= N; ++i)
			aval[i] = val[i];
	}
}

void rbfs(int x)
{
	int i, j, tm = -1, val[100];
	memset(val, 0, sizeof(val));
	val[x] = 50;
	xv[x] = 50;
	queue<int> q;
	q.push(x);
	bool inq[100];
	memset(inq, 0, sizeof(inq));
	while (!q.empty())
	{
		int fid = q.front();
		q.pop();
		for (i = 1; i <= N; ++i)
		{
			if (mat[fid][i] && val[i] == 0)
			{
				val[i] = val[fid] - 1;
				xv[i] = val[i];
				q.push(i);
			}
		}
	}
}
