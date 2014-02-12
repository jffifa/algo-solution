#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int b[3], c[3], ans[3];
int N, m, s, t, cnt;

int main()
{
	scanf("%d%d", &b[0], &c[0]);
	scanf("%d%d%d", &b[1], &t, &c[1]);
	scanf("%d", &b[2]);
	scanf("%d", &N);
	while (N--)
	{
		int now = 0;
		scanf("%d:%d", &m, &s);
		//printf("%d %d\n", m, s);
		if (m==0 && s<=6) continue;
		if (s) m++;
		cnt += m;
	}
	ans[0] = b[0]+c[0]*cnt;
	if (cnt > t) ans[1] = b[1]+c[1]*(cnt-t);
	else ans[1] = b[1];
	ans[2] = b[2];
	printf("Basic:     %d\n", ans[0]);
	printf("Combined:  %d\n", ans[1]);
	printf("Unlimited: %d\n", ans[2]);
	return 0;
}
