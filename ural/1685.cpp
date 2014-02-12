#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[20020], t[20020];
int now, len, pos[20020];

void gen(int l, int r)
{
	int m = l+r>>1;
	pos[m]=now++;
	if (m>l) gen(l, m-1);
	if (m<r) gen(m+1, r);
}

int main()
{
	gets(s);
	len = strlen(s);
	gen(0, len-1);
	for (int i = 0; i < len; ++i)
		t[i] = s[pos[i]];
	puts(t);
	return 0;
}
