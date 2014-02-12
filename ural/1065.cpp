#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef double db;

const db PI = acos(-1.0);
const db EPS = 1e-9;
const db INF = 1e10;

inline char DBLCMP(db d)
{
	if (fabs(d) < EPS) return 0;
	return d>0 ? 1 : -1;
}

struct spoint
{
	db x, y;
	spoint () {}
	spoint (db xx, db yy): x(xx), y(yy) {}
};

spoint operator - (const spoint &v1, const spoint &v2)
{return spoint(v1.x-v2.x, v1.y-v2.y);}

double norm(const spoint &v)
{return sqrt(v.x*v.x+v.y*v.y);}

double dis(const spoint &p1, const spoint &p2)
{return norm(p1-p2);}

double det(const spoint &v1, const spoint &v2)
{return v1.x*v2.y - v2.x*v1.y;}

double dir(const spoint &p0, const spoint &p1, const spoint &p2)
{return det(p1-p0, p2-p0);}

int N, M;
char qb[55][55]; 
spoint hmr[55];
spoint mdk[1001];
db d[55][55], f[55][55], ans;

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%lf%lf", &hmr[i].x, &hmr[i].y);
	reverse(hmr, hmr+N);
	for (int i = 0; i < M; ++i)
		scanf("%lf%lf", &mdk[i].x, &mdk[i].y);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			if (i==j) continue;
			qb[i][j] = 1;
			for (int k = 0; k < M; ++k)
				if (DBLCMP(dir(hmr[i], hmr[j], mdk[k])) <= 0)
				{
					qb[i][j] = 0;
					break;
				}
			d[i][j] = dis(hmr[i], hmr[j]);
			f[i][j] = INF;
		}
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < i+N; ++j)
			for (int k = i; k < j; ++k)
				if (f[i][k%N]<INF && qb[k%N][j%N]) f[i][j%N] = min(f[i][j%N], f[i][k%N]+d[k%N][j%N]);
	ans = INF;
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < i+N; ++j)
			for (int k = j+1; k < i+N; ++k)
				if (f[i][j%N]<INF && qb[j%N][k%N] && qb[k%N][i] && DBLCMP(dir(hmr[i], hmr[j%N], hmr[k%N]))!=0)
					ans = min(ans, f[i][j%N]+d[j%N][k%N]+d[k%N][i]);
	printf("%.2f\n", ans);
	return 0;
}
