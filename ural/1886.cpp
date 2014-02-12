#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const double INF = 1e20;
const double EPS = 1e-10;

struct se
{
	int u, v, t, d, p, a;
	se() {}
	se (int uu, int vv, int tt, int dd, int pp, int aa): u(uu), v(vv), t(tt), d(dd), p(pp), a(aa) {}
	void read() {scanf("%d%d%d%d%d%d", &u, &v, &t, &d, &p, &a);}
}e[100010];

int N, M;
vector<int> eid[100010];
double f[100010];
bool vis[100010];

inline bool cmp(const se &x, const se &y)
{return x.t < y.t;}

double find(int v, int t)
{
	if (v == N) return t;
	if (eid[v].empty() || e[eid[v][0]].t<t) return INF;
	int l=0, r=eid[v].size()-1, m;
	while (l < r)
	{
		m = l+r+1>>1;
		if (e[eid[v][m]].t >= t) l = m;
		else r = m-1;
	}
	return f[eid[v][l]];
}

int main()
{
	int i, j, u, v, t1, t2;
	double p, r1, r2;
	scanf("%d%d", &N, &M);
	for (i = M; i; --i)
		e[i].read();
	e[0] = se(0, 1, 0, 0, 0, 0);
	sort(e, e+M+1, cmp);
	for (i = M; i >= 0; --i)
	{
		u = e[i].u; v = e[i].v;
		t1 = e[i].t+e[i].d; t2 = t1+e[i].a;
		p = (e[i].p)/100.0;
		r1 = find(v, t1);
		if (r1 >= INF) {f[i] = INF; continue;}
		r2 = find(v, t2);
		if (r2 >= INF) {f[i] = INF; continue;}
		f[i] = (1-p)*r1+p*r2;
		if (eid[u].empty() || f[i]<f[eid[u].back()]) eid[u].push_back(i);
	}
	if (f[0] >= INF) puts("Fail");
	else printf("%.3f\n", f[0]);
	return 0;
}
