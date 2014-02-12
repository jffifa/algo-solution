#include <cstdio>
#include <cstring>

int hmr[7];

bool ok()
{
	if ((hmr[1]+hmr[2]+hmr[3])%2!=hmr[4]) return 0;
	if ((hmr[0]+hmr[2]+hmr[3])%2!=hmr[5]) return 0;
	if ((hmr[0]+hmr[1]+hmr[3])%2!=hmr[6]) return 0;
	return 1;
}

int main()
{
	for (int i = 0; i < 7; ++i)
		scanf("%d", hmr+i);
	if (ok())
	{
		for (int i = 0; i < 7; ++i)
			printf("%d ", hmr[i]);
		puts("");
		return 0;
	}
	for (int i = 0; i < 7; ++i)
	{
		hmr[i]^=1;
		if (ok())
		{
			for (int j = 0; j < 7; ++j)
				printf("%d ", hmr[j]);
			return 0;
		}
		hmr[i]^=1;
	}
	return 0;
}
