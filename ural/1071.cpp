#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x, y, lx, ly;
int sx[32], sy[32];

int tr(int x, int b, int s[])
{
	int len = 0;
	while (x)
	{
		s[len++] = x%b;
		x /= b;
	}
	return len;
}

int solve()
{
	if (x < y) return 0;
	int i, j, b;
	for (b = 2; b <= x; ++b)
	{
		memset(sx, 0, sizeof(sx));
		lx = tr(x, b, sx);
		memset(sy, 0, sizeof(sy));
		ly = tr(y, b, sy);
		i = 0;
		for (j = 0; j < ly; ++j)
		{
			while (i<lx && sx[i]!=sy[j]) ++i;
			if (i>=lx) break;
			++i;
		}
		if (j==ly) return b;
	}
	return 0;
}

int main()
{
	scanf("%d%d", &x, &y);
	int ans = solve();
	if (ans) printf("%d\n", ans);
	else puts("No solution");
}
