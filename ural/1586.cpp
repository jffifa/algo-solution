#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MOD = 1000000009;

vector<int> adj[200];
int N;
int p[200], pcnt=0;
int f[10002][200];

bool prime(int x)
{
	for (int i = 0; p[i]*p[i] <= x; ++i)
		if (x%p[i] == 0) return 0;
	return x>1;
}

void init()
{
	p[pcnt++] = 2;
	for (int i = 3; i < 1000; ++i)
		if (prime(i)) p[pcnt++] = i;
}

int main()
{
	int i, j, k;
	init();
	scanf("%d", &N);
	for (i = 25; i < pcnt; ++i)
		for (j = 25; j < pcnt; ++j)
			for (k = 0; k < 10; ++k)
				if ((p[i]%100)*10+k==p[j]) adj[i].push_back(j);
	for (i = 25; i < pcnt; ++i)
		f[3][i] = 1;
	for (i = 3; i < N; ++i)
		for (j = 25; j < pcnt; ++j)
			for (k = 0; k < adj[j].size(); ++k)
			{
				f[i+1][adj[j][k]] += f[i][j];
				if (f[i+1][adj[j][k]] > MOD) f[i+1][adj[j][k]] -= MOD;
			}
	int ans = 0;
	for (i = 25; i < pcnt; ++i)
	{
		ans += f[N][i];
		if (ans > MOD) ans -= MOD;
	}
	printf("%d\n", ans);
	return 0;
}
