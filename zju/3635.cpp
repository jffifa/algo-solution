#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

inline int lowbit(int x) {
	return x&-x;
}

int N, M;
int ta[55555];
int ans[55555];

void update(int p, int d) {
	for (; p <= N; p += lowbit(p))
		ta[p] += d;
}

int getsum(int p) {
	int res = 0;
	for (; p; p -= lowbit(p))
		res += ta[p];
	return res;
}

int find(int rnk) { 
	int b, p; 
	for (b = 1; b <= N; b <<= 1); 
	b >>= 1; 
	for (p = 0; b; b >>= 1) 
		if ((p|b)<=N && ta[p|b]<=rnk) 
			rnk -= ta[p|=b]; 
	if (rnk) return -1; 
	else return p+1-1; 
}

int main() {
	int i, j, k, x;
	while (cin>>N) {
		memset(ta, 0, sizeof ta);
		for (i = 1; i <= N; ++i)
			update(i, 1);
		for (i = 1; i <= N; ++i) {
			scanf("%d", &x);
			ans[i] = find(x-1)+1;
			update(ans[i], -1);
		}
		cin>>M;
		while (M--) {
			scanf("%d", &x);
			printf("%d%c", ans[x], M==0?'\n':' ');
		}
	}
	return 0;
}
