#include <cstdio>
#include <cstring>

int main()
{
	int x;
	scanf("%d", &x);
	int cnt=0;
	int cut[40];
	while (x>1)
	{
		cut[cnt++] = x>>1;
		x -= x>>1;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i)
		printf("%d ", cut[i]);
	puts("");
	return 0;
}
