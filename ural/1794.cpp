#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, id, ans, x;
int cnt[100010];

int main()
{
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &x);
		x--;
		cnt[(i+N-x)%N]++;
	}
	ans = 0;
	for (i = 0; i < N; ++i)
		if (cnt[i]>ans)
		{
			ans = cnt[i];
			id = i;
		}
	printf("%d\n", id+1);
	return 0;
}
