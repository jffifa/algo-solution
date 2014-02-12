#include <cstdio>
#include <cstring>

char hmr[6][6], mdk[6][6], ans[20];

void rotate()
{
	char tmp[6][6];
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			tmp[i][j] = hmr[3-j][i];
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			hmr[i][j] = tmp[i][j];
}

int main()
{
	for (int i = 0; i < 4; ++i)
		scanf("%s", hmr[i]);
	for (int i = 0; i < 4; ++i)
		scanf("%s", mdk[i]);
	for (int i = 0; i < 4; ++i)
	{
		int j = 0;
		for (int p = 0; p < 4; ++p)
			for (int q = 0; q < 4; ++q)
			if (hmr[p][q] == 'X')
			{
				ans[i*4+j] = mdk[p][q];
				j++;
			}
		rotate();
	}
	puts(ans);
	return 0;
}
