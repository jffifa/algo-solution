#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s[60];
vector<int> ans;
int N;

void calc(int x)
{
	int t = x, sum = 0;
	while (t)
	{
		sum += t%10;
		t /= 10;
	}
	s[sum].push_back(x);
}

int main()
{
	int i, j;
	for (i = 1; i <= 99999; ++i)
		calc(i);
	scanf("%d", &N);
	i = 45;
	while (N)
	{
		while (s[i].empty()||i>N) --i;
		N -= i;
		j = s[i].back();
		s[i].pop_back();
		ans.push_back(j);
	}
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	return 0;
}
