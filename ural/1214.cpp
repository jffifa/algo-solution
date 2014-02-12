#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int x, y;

void solve(int &x, int &y) {
	if (!(x>0 && y>0)) return;
	if (x+y&1) swap(x, y);
}

int main() {
	cin>>x>>y;
	solve(x, y);
	cout<<x<<' '<<y<<'\n';
	return 0;
}
