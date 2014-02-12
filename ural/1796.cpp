#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int high, low;
int sum, ticket;
int num[6];
int w[6] = {10, 50, 100, 500, 1000, 5000};

int main()
{
	int i, j, k;
	for (i = 0; i < 6; ++i)
	{
		scanf("%d", num+i);
		sum += num[i]*w[i];
	}
	scanf("%d", &ticket);
	high = sum/ticket; low = 0;
	for (i = 0; i < 6; ++i)
		if (num[i])
		{
			sum -= w[i];
			low = max(low, sum/ticket);
			sum += w[i];
		}
	printf("%d\n", high-low);
	for (i = low+1; i <= high; ++i)
		printf("%d ", i);
	puts("");
	return 0;
}
