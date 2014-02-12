#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt;
vector<int> c[50];

int main()
{
	int u, v;
	scanf("%d", &N);
	N = (int)((1.0+sqrt(1.0+8.0*N))/2.0);
	cnt = 0;
	for (u = 1; u <= N; ++u)
		for (v = u+1; v <= N; ++v)
		{
			cnt++;
			c[u].push_back(cnt);
			c[v].push_back(cnt);
		}
	printf("%d\n", N);
	for (u = 1; u <= N; ++u)
	{
		printf("%d", c[u].size());
		for (int i = 0; i < c[u].size(); ++i)
			printf(" %d", c[u][i]);
		puts("");
	}
	return 0;
}
