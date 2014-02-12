#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a, b;

int main()
{
	scanf("%d%d", &a, &b);
	if (a%2==0||b%2==1) puts("yes");
	else puts("no");
	return 0;
}
