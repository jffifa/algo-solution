#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, len;
char s[60];

void genstr(int m, int len)
{
	int i, j;
	for (i = 0; i < len; ++i)
		s[i] = ' ';
	s[len/2] = '0'+m;
	for (i = m-1, j = len/2-2; i>=0; --i, j -= 2)
		s[j] = '0'+i;
	for (i = m-1, j = len/2+2; i>=0; --i, j += 2)
		s[j] = '0'+i;
	for (i = len-1; s[i]<'0'||s[i]>'9'; --i)
		s[i] = 0;
	puts(s);
}

int main()
{
	int i, j;
	scanf("%d", &N);
	len = N*4+1;
	for (i = 0; i < N; ++i)
		genstr(i, len);
	genstr(N, len);
	for (i = N-1; i >= 0; --i)
		genstr(i, len);
	return 0;
}
