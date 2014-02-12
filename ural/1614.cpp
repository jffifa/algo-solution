#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int N, M;

int main() {
	int i, j, k;
	cin>>N;
	M = N*2;
	for (i = 0; i < N; ++i) {
		int now = i;
		printf("%d", now+1);
		for (j = 1; j < M; ++j) {
			now = (now+j)%M;
			printf(" %d", now+1);
		}
		puts("");
	}
	return 0;
}
