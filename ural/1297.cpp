#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, len, pos;
char s[1010], t[2020];

void check(int p)
{
	int i = p, j = p+1;
	while (i>=0 && j<N && t[i]==t[j])
	{
		--i;
		++j;
	}
	if (j-i-1>len)
	{
		pos = p;
		len = j-i-1;
	}
}

int main()
{
	int i, j;
	scanf("%s", s);
	N = strlen(s);
	for (i = 0; i < N; ++i)
		t[i*2] = t[i*2+1] = s[i];
	len = 0;
	N *= 2;
	for (i = 0; i < N-1; i++)
		check(i);
	//printf("%d\n", len/2);
	len /= 2;
	pos = (pos+1)/2;
	for (i = pos-len/2; i < pos-len/2+len; ++i)
		putchar(s[i]);
	return 0;
}

