#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

struct sp
{
	int x, y;
	sp() {}
	sp(int xx, int yy): x(xx), y(yy) {}
	void read() {scanf("%d%d", &x, &y);}
	void write() {printf("%d %d\n", x, y);}
};

bool operator< (const sp &p1, const sp &p2)
{
	if (p1.y==p2.y) return p1.x>p2.x;
	return p1.y>p2.y;
}

sp operator- (const sp &v1, const sp &v2)
{return sp(v1.x-v2.x, v1.y-v2.y);}

int det(const sp &v1, const sp &v2)
{return v1.x*v2.y-v2.x*v1.y;}

int dir(const sp &p0, const sp &p1, const sp &p2)
{return det(p1-p0, p2-p0);}

bool sameline(const sp &p0, const sp &p1, const sp &p2)
{return dir(p0, p1, p2)==0;}

int graham(int N, sp p[], sp ch[])
{
	int i, j, k;
	if (N<3)
	{
		for (int i = 0; i < N; ++i) ch[i] = p[i];
		return N;
	}
	sort(p, p+N);
	ch[0] = p[0];
	ch[1] = p[1];
	for (i = j = 2; i < N; ch[j++]=p[i++])
		while (j>1 && dir(ch[j-1], ch[j-2], p[i])>0) --j;
	ch[k=j++] = p[N-2];
	for (i = N-3; i > 0; ch[j++]=p[i--])
		while (j>k && dir(ch[j-1], ch[j-2], p[i])>0) --j;
	while (j>k && dir(ch[j-1], ch[j-2], ch[0])>0) --j;
	return j;
}

set<sp> s;
sp p, now[4004], ch[4004];
int N, M, ans;

int main()
{
	scanf("%d", &N);
	/*	
	for (int i = 0; i < N; ++i)
		now[i].read();
	M = graham(N, now, ch);
	for (int i = 0; i < M; ++i)
		now[i].write();
	*/
		
	for (int i = 0; i < N; ++i)
	{
		p.read();
		s.insert(p);
	}
	while (!s.empty())
	{
		int i, M;
		set<sp>::iterator it;
		for (i=0, it = s.begin(); it != s.end(); ++i, ++it)
			now[i] = *it;
		M = graham(i, now, ch);
		if (M < 3) break;
		bool flag = 1;
		for (int i = 0; i < M-2; ++i)
			if (!sameline(ch[i], ch[i+1], ch[i+2]))
			{
				flag = 0;
				break;
			}
		if (flag) break;
		++ans;
		for (i=0; i < M; ++i)
			s.erase(ch[i]);
	}
	printf("%d\n", ans);
	return 0;
}
