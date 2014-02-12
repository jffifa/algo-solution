/*
	Problem: 1197
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
using namespace std;

char p[4];
int r, c;
int ans;

int cnt(int r, int c)
{
	if (r<0||r>7||c<0||c>7) return 0;
	return 1;
}

int T;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", p);
		r = p[0]-'a';
		c = p[1]-'1';
		ans = 0;
		ans += cnt(r+1, c+2);
		ans += cnt(r+1, c-2);
		ans += cnt(r-1, c+2);
		ans += cnt(r-1, c-2);
		ans += cnt(r+2, c+1);
		ans += cnt(r+2, c-1);
		ans += cnt(r-2, c+1);
		ans += cnt(r-2, c-1);
		printf("%d\n", ans);
	}
	return 0;
}
