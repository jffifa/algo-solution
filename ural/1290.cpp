#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int a[25005], b[25005];

int main()
{
	int i, j, x;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", a+i);
	sort(a, a+N);
	reverse(a, a+N);
	for (i = 0; i < N; ++i)
		printf("%d\n", a[i]);
	/*
	while (N--)
	{
		scanf("%d", &x);
		a[x]++;
	}
	for (i = 25000; i >= 1; --i)
		a[i-1] += a[i];
	for (i = 1; a[i]; ++i)
		b[a[i]]++;
	for (i = 25000; i >= 1; --i)
		b[i-1] += b[i];
	for (i = 1; !b[i]; ++i);
	for (; b[i]; ++i)
		printf("%d\n", b[i]);
	*/
	return 0;
}
