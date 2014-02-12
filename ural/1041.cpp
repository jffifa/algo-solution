#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 971027;
const int MAXN = 55;

struct sv {int id, cost;}v[2020];
bool operator<(const sv &v1, const sv &v2)
{
	if (v1.cost==v2.cost) return v1.id<v2.id;
	return v1.cost < v2.cost;
}

int M, N;
LL a[2020][MAXN];
int first[2020];
int ref[55];
int cost;
vector<int> ans;

LL gcd(LL p, LL q)
{
	LL r;
	while (q)
	{
		r = p%q;
		p = q;
		q = r;
	}
	return p;
}

int gauss(int i)
{
	int j, k;
	for (j = 0; j < N; ++j)
	{
		if (a[i][j]==0) continue;
		if (ref[j]==-1) return j;
		LL t = gcd(abs(a[i][j]), abs(a[ref[j]][j]));
		LL p = a[ref[j]][j]/t, q = a[i][j]/t;
		for (k = j; k < N; ++k)
			a[i][k] = (a[i][k]*p-a[ref[j]][k]*q)%MOD;
	}
	return -1;
}

int main()
{
	int i, j, k;
	scanf("%d%d", &M, &N);
	for (i = 0; i < M; ++i)
		for (j = 0; j < N; ++j)
			scanf("%lld", &a[i][j]);
	for (i = 0; i < M; ++i)
	{
		scanf("%d", &v[i].cost);
		v[i].id = i;
	}
	sort(v, v+M);
	memset(ref, 255, sizeof(ref));
	for (i = 0; i < M; ++i)
	{
		j = gauss(v[i].id);
		if (j != -1)
		{
			ref[j] = v[i].id;
			cost += v[i].cost;
			ans.push_back(v[i].id+1);
		}
		if (ans.size()==N) break;
	}
	if (ans.size()<N)
		puts("0");
	else
	{
		printf("%d\n", cost);
		sort(ans.begin(), ans.end());
		for (i = 0; i < N; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}
