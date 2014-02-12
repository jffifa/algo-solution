#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> cnt;
int ans;

void f(pair<int, int> x)
{
	if (x.second == 3) ++ans;
}

int main()
{
	int i, j, k, N;
	for (i = 0; i < 3; ++i)
	{
		scanf("%d", &N);
		for (j = 0; j < N; ++j)
		{
			scanf("%d", &k);
			cnt[k]++;
		}
	}
	for_each(cnt.begin(), cnt.end(), f);
	printf("%d\n", ans);
	return 0;
}
