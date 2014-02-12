#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 4004;
const int INF = 0x3fffffff;

bool pld[MAX][MAX];
char s[MAX];
int N, f[MAX], pre[MAX];

void judge(int i, int j)
{
	while (i>=0 && j<N && s[i]==s[j])
		pld[i--][j++] = 1;
}

void print(int i)
{
	if (i==0) return;
	print(pre[i]);
	for (int j = pre[i]; j < i; ++j)
		putchar(s[j]);
	if (i!=N) putchar(' ');
	else puts("");
}

int main()
{
	int i, j, k;
	scanf("%s", s);
	N = strlen(s);
	for (i = 0; i < N; ++i)
	{
		judge(i, i);
		if (i) judge(i-1, i);
	}
	f[0] = 0;
	for (i = 1; i <= N; ++i)
	{
		f[i] = INF;
		for (j = 0; j < i; ++j)
			if (pld[j][i-1] && f[j]+1<f[i])
			{
				f[i] = f[j]+1;
				pre[i] = j;
			}
	}
	cout<<f[N]<<endl;
	print(N);
	return 0;
}
