#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
double f[404][404], sum[404][404];
double ans;

int main() {
	int i, j, k;
	cin>>N;
	f[1][0] = 1;
	for (j = 0; j < N; ++j)
		sum[1][j] = 1;
	for (i = 2; i < N; ++i)
	{
		for (j = 1; j < i; ++j)
		{
			for (k = 1; k < i; ++k)
				f[i][j] += f[k][j-1]*sum[i-k][j-1]+f[i-k][j-1]*sum[k][j-1]-f[k][j-1]*f[i-k][j-1];
			f[i][j] /= i-1;
		}
		for (j = 1; j < N; ++j)
			sum[i][j] = sum[i][j-1]+f[i][j];
	}
	for (j = 1; j < N-1; ++j)
		ans += j*f[N-1][j];
	printf("%.8f\n", ans*10);
	return 0;
}
