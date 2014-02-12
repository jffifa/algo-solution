#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
double x, sum;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &x);
		sum += x;
	}
	printf("%.6f\n", sum/N);
	return 0;
}
