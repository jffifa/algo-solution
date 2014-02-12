#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int g[4][4];
int pr[4][4], pc[4][4]; 
int cnt[4][4];
int ans=9999;

void rot(int &r, int &c)
{
	int nr = c;
	int nc = 3-r;
	r = nr;
	c = nc;
}

int main()
{
	int i, j, k, r, c;
	for (r = 0; r < 4; ++r)
		for (c = 0; c < 4; ++c)
			scanf("%d", &g[r][c]);
	for (i = 0; i < 4; ++i)
	{
		r = i/2; c = i%2;
		for (j = 0; j < 4; ++j)
		{
			pr[i][j] = r;
			pc[i][j] = c;
			if (g[r][c]==1)
			{
				for (k = 0; k < 4; ++k)
				{
					cnt[i][k] = (k+4-j)%4;
					if (cnt[i][k]>2) cnt[i][k] = 4-cnt[i][k];
				}
				break;
			}
			rot(r, c);
		}
	}
	for (i = 0; i < 4; ++i)
	{
		int tmp = 0;
		for (j = 0; j < 4; ++j)
			tmp += cnt[j][i];
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}
