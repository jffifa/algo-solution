#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL INF = 9223372036854775807LL;

set<LL> s;
LL a, b, c;

int main()
{
	scanf("%lld%lld%lld", &a, &b, &c);
	if (a==b||b==c||c==a)
	{
		puts("1");
		return 0;
	}
	s.insert(a); s.insert(b); s.insert(c);
	set<LL>::iterator i,j;
	int ans = 1;
	while (1)
	{
		LL m = INF;
		i = j = s.begin(); j++;
		for (; j != s.end(); ++i, ++j)
			m = min(m, (*j)-(*i));
		ans++;
		if (s.count(m)) break;
		else s.insert(m);
	}
	printf("%d\n", ans);
	return 0;
}
