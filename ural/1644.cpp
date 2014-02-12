#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, num, high, low;
char str[20];

int main()
{
	scanf("%d", &N);
	high = 10; low = 2;
	while (N--)
	{
		scanf("%d%s", &num, str);
		if (str[0] == 's')
			high = min(high, num);
		else
			low = max(low, num);
		//printf("%d\n", num);
	}
	if (low >= high)
		puts("Inconsistent");
	else
		printf("%d\n", high);
	return 0;
}
