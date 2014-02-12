#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a, b, s, t;

int main()
{
	scanf("%d%d%d%d", &a, &b, &s, &t);
	if (t>s)
		printf("%d\n", 2*b*(t-s)+a*(t-s-1));
	else
		printf("%d\n", 2*b*(s-t)+a*(s-t+1));
	return 0;
}
