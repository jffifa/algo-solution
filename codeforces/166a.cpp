#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pr;
pr (*mkpr)(int, int)=make_pair;

int N, K;
pr team[200];
int rank[200];

bool cmp(pr u, pr v)
{
	if (u.first==v.first) return u.second<v.second;
	return u.first>v.first;
}

int main()
{
	scanf("%d%d", &N, &K);
	K--;
	int i, j, k;
	for (i = 0; i < N; ++i)
		scanf("%d%d", &team[i].first, &team[i].second);
	/*
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
		{
			if (i==j) continue;
			if (team[j].first>team[i].first||(team[j].first==team[i].first&&team[j].second<team[i].second))
				++rank[i];
		}
	*/
	sort(team, team+N, cmp);
	int ans = 0;
	for (i = 0; i < N; ++i)
		if (team[i]==team[K]) ++ans;
	printf("%d\n", ans);
	return 0;
}
