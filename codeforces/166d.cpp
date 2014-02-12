#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
int N, M;
LL ans;
LL f[100010][3];
int g[100010][3];
int h[100010][3];
int ansc[100010], anss[100010];

struct snode
{
	int id;
	int s, p;
	snode() {}
	snode(int a, int b): s(a), p(b) {}
	void read() {cin>>p>>s;}
	bool operator<(const snode &rhs) const
	{
		if (s==rhs.s) return p<rhs.p;
		return s<rhs.s;
	}
};
snode shoe[100010];
snode cus[100010];

int main()
{
	int i, j, k, find;
	cin>>N;
	for (i = 1; i <= N; ++i)
	{
		shoe[i].id = i;
		shoe[i].read();
	}
	cin>>M;
	for (i = 1; i <= M; ++i)
	{
		cus[i].id = i;
		cus[i].read();
	}
	sort(shoe+1, shoe+1+N);
	sort(cus+1, cus+1+M);
	memset(f, 255, sizeof(f));
	f[0][0] = 0;
	LL x;
	snode node, tmp;
	for (i = 1; i <= N; ++i)
	{
		x = -1;
		for (j = 0; j < 3; ++j)
			if (f[i-1][j]>x) {x = f[i-1][j]; k = j;}
		f[i][0] = f[i-1][k];
		g[i][0] = 0;
		h[i][0] = k;
		find = lower_bound(cus+1, cus+1+M, shoe[i])-cus;
		//cout << find << endl;
		if (cus[find].s==shoe[i].s)
		{
			f[i][2] = f[i-1][k]+shoe[i].p;
			g[i][2] = find;
			h[i][2] = k;
		}
		tmp = shoe[i]; tmp.s--;
		find = lower_bound(cus+1, cus+1+M, tmp)-cus;
		if (cus[find].s!=tmp.s) continue;
		f[i][1] = f[i-1][0]+shoe[i].p;
		g[i][1] = find;
		h[i][1] = 0;
		if (g[i-1][1] && f[i-1][1]+shoe[i].p>f[i][1])
		{
			f[i][1] = f[i-1][1]+shoe[i].p;
			h[i][1] = 1;
		}
		if (g[i-1][2]==find) find++;
		if (cus[find].s!=tmp.s) continue;
		if (g[i-1][2] && f[i-1][2]+shoe[i].p>f[i][1])
		{
			f[i][1] = f[i-1][2]+shoe[i].p;
			g[i][1] = find;
			h[i][1] = 2;
		}
	}
	//cout << f[1][2] << endl;
	x = -1;
	for (j = 0; j < 3; ++j)
		if (f[N][j]>x) {x = f[N][j]; k = j;}
	ans = x;
	int cnt = 0;
	for (i = N; i > 0; --i)
	{
		if (g[i][k])
		{
			ansc[cnt] = cus[g[i][k]].id;
			anss[cnt] = shoe[i].id;
			cnt++;
		}
		k = h[i][k];
	}
	cout << ans << endl;
	printf("%d\n", cnt);
	for (i = 0; i < cnt; ++i)
		printf("%d %d\n", ansc[i], anss[i]);
	return 0;
}
