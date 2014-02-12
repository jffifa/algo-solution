#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
char ans[22][22];

int main() {
	while (cin>>N>>M) {
		if (N < M) swap(N, M);
		puts(ans[N][M]);
	}
	return 0;
}
