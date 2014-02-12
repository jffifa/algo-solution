#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int N, ans;
string s;
set<string> hmr;

int main()
{
	scanf("%d", &N);
	getchar();
	while (N--)
	{
		getline(cin, s);
		if (hmr.count(s)) ++ans;
		else hmr.insert(s);
	}
	printf("%d\n", ans);
	return 0;
}
