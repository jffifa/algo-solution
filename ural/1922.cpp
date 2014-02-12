#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
struct snode {
	int a, id;
	bool operator<(const snode &rhs) const {
		return a < rhs.a;
	}
}node[1111];
vector<int> ans[1111];

int main() {
	int i, j, k;
	cin>>N;
	for (i = 0; i < N; ++i) {
		cin>>node[i].a;
		node[i].id = i;
	}
	sort(node, node+N);
	int mx = node[N-1].a;
	int cnt = 0;
	for (i = 1; i <= mx; ++i) {
		if (i > N) continue;
		if (node[i-1].a<=i && (i==N||node[i].a>i+1)) {
			++cnt;
			ans[i].clear();
			for (j = 0; j < i; ++j)
				ans[i].push_back(node[j].id+1);
		}
	}
	printf("%d\n", cnt);
	for (i = 1; i <= mx; ++i)
		if (ans[i].size()) {
			printf("%d", ans[i].size());
			for (j = 0; j < ans[i].size(); ++j)
				printf(" %d", ans[i][j]);
			puts("");
		}
	//sort(a, a+N);
	return 0;
}
