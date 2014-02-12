#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, res, mx, ans;
int cnt[111];
char team[12][99], teamcmp[99];
char bet[99];

int main()
{
	int i, j, k;
	for (i = 0; i < 12; ++i)
		gets(team[i]);
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &M);
		getchar();
		while (M--)
		{
			gets(bet);
			for (j = 0; bet[j] != ':'; ++j);
			if (bet[j+2]=='g') res = 0;
			else if (bet[j+2]=='s') res = 1;
			else res = 2;
			memset(teamcmp, 0, sizeof(teamcmp));
			strncpy(teamcmp, bet, j-1);
			//printf("%d %s; ", res, teamcmp);
			for (j = 0; j < 12; ++j)
				if (strcmp(team[j], teamcmp)==0)
				{
					if (res==j/4) ++cnt[i];
					break;
				}
		}
		//printf("%d\n", cnt[i]);
	}
	sort(cnt, cnt+N);
	mx = cnt[N-1];
	for (i = 0; i < N; ++i)
		ans += cnt[i]==mx;
	printf("%d\n", ans*5);
	return 0;
}
