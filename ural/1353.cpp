#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int S;
int f[11][111], ans;

int main()
{
	int i, j, k;
	scanf("%d", &S);
	for (j = 1; j <= 9; ++j)
		f[1][j] = 1;
	for (i = 2; i <= 9; ++i)
		for (j = 1; j <= S; ++j)
			for (k = 0; k <= min(9, j); ++k)
				f[i][j] += f[i-1][j-k];
	f[10][1] = 1;
	for (i = 1; i <= 10; ++i)
		ans += f[i][S];
	printf("%d\n", ans);
	return 0;
}
