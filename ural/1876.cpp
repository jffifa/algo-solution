#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a, b;

int main()
{
	scanf("%d%d", &a, &b);
	printf("%d\n", max(2*b+40, 2*a+39));
	return 0;
}
