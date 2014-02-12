#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct ss
{
	int l, r;
}s[100100], ans[100100];
bool operator<(const ss &a, const ss &b)
{
	if (a.l == b.l) return a.r > b.r;
	return a.l < b.l;
}

int N, M, K, l, r, now;

int main()
{
	int i, j, k;
	scanf("%d", &M);
	while (scanf("%d%d", &l, &r), l||r)
	{
		if (r < 0) continue;
		s[N].l = l;
		s[N].r = r;
		N++;
	}
	if (!N) {puts("No solution"); return 0;}
	sort(s, s+N);
	for (i=1, j=1; i < N; ++i)
		if (s[i].l>s[j-1].l && s[i].r>s[j-1].r) s[j++] = s[i];
	N = j;
	K = now = 0;
	s[N].l = s[N].r = M+1;
	for (i = 0; i<N && now<M; ++i)
	{
		if (s[i].l > now) {K = 0; break;}
		if (s[i+1].l > now)
		{
			ans[K++] = s[i];
			now = s[i].r;
		}
	}
	if (!K || now<M)
		puts("No solution");
	else
	{
		printf("%d\n", K);
		for (i = 0; i < K; ++i)
			printf("%d %d\n", ans[i].l , ans[i].r);
	}
	return 0;
}