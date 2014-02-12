#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
char s[1002][10], c[10];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%s", s[i]);
	scanf("%s", c);
	for (int i = 0; i < N; ++i)
		if (s[i][0] == c[0]) puts(s[i]);
	return 0;
}
