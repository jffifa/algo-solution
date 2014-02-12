#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
int ord[20];
string s[20][3], ans[20];

int main()
{
	int i, j;
	cin >> N;
	for (i = 0; i < N; ++i)
		for (j = 0; j < 3; ++j)
			cin >> s[i][j];
	for (i = 0; i < N; ++i)
	{
		cin >> ord[i];
		ord[i]--;
	}
	//printf("%d\n", N);
	for (i = 0; i < N; ++i)
	{
		sort(s[ord[i]], s[ord[i]]+3);
		/*
		for (j = 0; j < 3; ++j)
			cout<<s[i][j]<<' ';
		*/
		if (i==0) ans[i] = s[ord[i]][0];
		else
		{
			for (j = 0; j < 3; ++j)
			if (s[ord[i]][j]>ans[i-1])
			{
				ans[i] = s[ord[i]][j];
				break;
			}
			if (j==3)
			{
				//printf("%d\n", i);
				puts("IMPOSSIBLE");
				return 0;
			}
		}
		//cout << ans[i] << endl;
	}
	
	for (i = 0; i < N; ++i)
		cout << ans[i] << endl;
	
	return 0;
}
