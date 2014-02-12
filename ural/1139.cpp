#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;

int main() {
	int i, j, ans;
	while (cin>>N>>M) {
		--N; --M;
		i = j = 1;
		ans = 1;
		while (i!=N || j!=M) {
			//printf("%d %d\n", i, j);
			if (N*j>i*M) i++;
			else if (N*j<i*M) j++;
			else i++, j++;
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
