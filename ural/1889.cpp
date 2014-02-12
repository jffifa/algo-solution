#include <iostream>
#include <string>
#include <set>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string ph[1010];
string un("unknown");
set<string> lang;
vector<int> ans;

int main()
{
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		cin >> ph[i];
	for (i = 1; i <= N; ++i)
	{
		if (N%i) continue;
		lang.clear();
		bool hmr = 1;
		for (j = 0; j < N; j += i)
		{
			string now;
			for (k = j; k<j+i; ++k)
				if (ph[k] != un) {now = ph[k]; break;}
			if (k==j+i) continue;
			if (lang.count(now)) {hmr = 0; break;}
			lang.insert(now);
			for (k++; k < j+i; ++k)
				if (ph[k]!=un && ph[k]!=now)
				{
					//cout<<"1: "<<ph[k]<<endl;
					//cout<<"2: "<<now<<endl;
					hmr = 0;
					break;
				}
			if (!hmr) break;
		}
		if (hmr) ans.push_back(N/i);
	}
	sort(ans.begin(), ans.end());
	if (ans.size())
	{
		for (i = 0; i < ans.size(); ++i)
		{
			if (i) putchar(' ');
			printf("%d", ans[i]);
		}
		puts("");
	}
	else
		puts("Igor is wrong.");
	return 0;
}
