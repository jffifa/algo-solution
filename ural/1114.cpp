#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
ull c[40][40];

ull comb(int x, int y) {
	if (c[x][y] != 0ull)
		return c[x][y];

	if (x == y) {
		return c[x][y] = 1ull;
	}
	if (x == 0) {
		return c[x][y] = 1ull;
	}

	return c[x][y] = comb(x - 1, y- 1) + comb(x, y-1);
}

int main()
{
	int N, A, B;
	memset(c, 0, sizeof c);
	while (~scanf("%d%d%d", &N, &A, &B)) {
		ull sumA = 0ull, sumB = 0ull;
		for (int i = 0; i <= A; ++i) {
			sumA += comb(i, i + N - 1);
		}
		for (int i = 0; i <= B; ++i) {
			sumB += comb(i, i + N - 1);
		}
		printf("%llu\n", sumA * sumB);
	}
}
