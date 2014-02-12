//ural1178
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct sp
{
	int x, y;
	int id;
	void read() {scanf("%d%d", &x, &y);}
}p[11111];
inline bool operator<(const sp &u, const sp &v)
{
	if (u.y==v.y) return u.x<v.x;
	return u.y<v.y;
}

int N;

int main()
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
	{
		p[i].read();
		p[i].id = i+1;
	}
	sort(p, p+N);
	for (i = 0; i < N; i+=2)
		printf("%d %d\n", p[i].id, p[i+1].id);
	return 0;
}
