#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int N, M, ans;
int a[20000];
//set<int> list;

int main()
{
	int i, j, x;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", a+i);
	scanf("%d", &M);
	while (M--)
	{
		scanf("%d", &x);
		ans += binary_search(a, a+N, x);
	}
	printf("%d\n", ans);
	return 0;
}
