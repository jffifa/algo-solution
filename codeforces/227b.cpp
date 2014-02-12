#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, M;
int a[111111], pos[111111];
int q;

int main() {
	int i, j, k;
	cin>>N;
	for (i = 0; i < N; ++i) {
		cin>>a[i];
		pos[a[i]] = i;
	}
	cin>>M;
	ll f=0, g=0;
	while (M--) {
		cin>>q;
		f += pos[q]+1;
		g += N-pos[q];
	}
	cout<<f<<' '<<g<<'\n';
	return 0;
}
