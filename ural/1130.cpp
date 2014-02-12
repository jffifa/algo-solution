#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct sp
{
	int x, y;
	sp() {}
	sp(int xx, int yy): x(xx), y(yy) {}
	void read() {scanf("%d%d", &x, &y);}
};

int N, L, f[20002], cnt, tr[3];
char s[20002];
sp p[20002];

inline bool check(int x, int y)
{return x*x+y*y<=L*L;}

bool merge(int a, int b)
{
	if (check(p[a].x+p[b].x, p[a].y+p[b].y))
	{
		p[a].x += p[b].x;
		p[a].y += p[b].y;
		f[b] = a;
		s[b] = 0;
		return 1;
	}
	if (check(p[a].x-p[b].x, p[a].y-p[b].y))
	{
		p[a].x -= p[b].x;
		p[a].y -= p[b].y;
		f[b] = a;
		s[b] = 1;
		return 1;
	}
	return 0;
}

void solve()
{
	for (int k = 0; k < 2; ++k)
		for (int j = k+1; j < 3; ++j)
			if (merge(tr[k], tr[j]))
			{
				tr[j] = tr[2];
				return;
			}
	while (1) {puts("here");}
}

char homura(int i)
{
	if (f[i]==i) return s[i];
	s[i] = s[i]^homura(f[i]);
	f[i] = i;
	return s[i];
}

int main()
{
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; ++i)
	{
		p[i].read();
		f[i] = i;
		s[i] = 0;
	}
	puts("YES");
	if (N==1)
	{
		puts("+");
		return 0;
	}
	tr[0] = 0; tr[1] = 1;
	int now = 2;
	while (now < N)
	{
		tr[2] = now++;
		solve();
	}
	f[tr[1]] = f[tr[0]];
	int sx=p[tr[0]].x+p[tr[1]].x;
	int sy=p[tr[0]].y+p[tr[1]].y;
	if (sx*sx+sy*sy>2*L*L)
		s[tr[1]] = 1;
	for (int i = 0; i < N; ++i)
	{
		homura(i);
		if (s[i]) putchar('-');
		else putchar('+');
	}
	puts("");
	return 0;
}

