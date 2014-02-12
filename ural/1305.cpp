/*
	Problem: Ural1305
	Algorithm: Geometry, Maths
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 0x3fffffff;

struct sp
{
	int x, y;
	sp() {}
	sp(int xx, double yy): x(xx), y(yy) {}
	void read() {scanf("%d%d", &x, &y);}
	void print() {printf("%d %d\n", x, y);}
};

bool operator== (const sp &p1, const sp &p2)
{return p1.x==p2.x&&p1.y==p2.y;}

int N;
sp p[100001];
int u, d, l, r, lu, ld, rd, ru;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		p[i].read();
	r = u = -INF;
	l = d = INF;
	for (int i = 0; i < N; ++i)
	{
		u = max(u, p[i].y);
		d = min(d, p[i].y);
		r = max(r, p[i].x);
		l = min(l, p[i].x);
	}
	rd = ld = INF;
	lu = ru = -INF;
	for (int i = 0; i < N; ++i)
	{
		rd = min(rd, p[i].y-p[i].x);
		lu = max(lu, p[i].y-p[i].x);
		ld = min(ld, p[i].y+p[i].x);
		ru = max(ru, p[i].y+p[i].x);
	}
	p[7].x = l; p[7].y = ld-l;
	p[6].x = l; p[6].y = l+lu;
	p[5].y = u; p[5].x = u-lu;
	p[4].y = u; p[4].x = ru-u;
	p[3].x = r; p[3].y = ru-r;
	p[2].x = r; p[2].y = rd+r;
	p[1].y = d; p[1].x = d-rd;
	p[0].y = d; p[0].x = ld-d;
	for (int i = 0; i < 8; ++i)
	{
		char flag = 1;
		for (int j = 0; j < i; ++j)
			if (p[i] == p[j]) flag = 0;
		if (flag) p[i].print();
	}
	return 0;
}
