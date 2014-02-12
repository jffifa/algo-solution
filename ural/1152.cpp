#include <cstdio>
#include <cstring>
using namespace std;

const int MAXS = 1<<20;
const int INF = 0x3fffffff;

inline int min(int a, int b)
{return a<b?a:b;}

int N;
int f[MAXS];
int r, sta;
int dmg[22];

int dfs(int s)
{
	if (f[s]>=0) return f[s];
	int d = 0;
	for (int i = 0; i < N; ++i)
		if (s&(1<<i)) d+= dmg[i];
	int best=INF, mask;
	//1
	mask = 1;
	for (int i = 0; i < N; ++i)
	{
		if (!(s&mask)) best = min(best, dfs(s|mask));
		mask<<=1;
	}
	//2
	if (N>1)
	{
		mask = 3;
		for (int i = 0; i < N-1; ++i)
		{
			if (!(s&mask)) best = min(best, dfs(s|mask));
			mask<<=1;
		}
		mask = (1<<N-1)|1;
		if (!(s&mask)) best = min(best, dfs(s|mask));
	}
	//3
	if (N>2)
	{
		mask = 7;
		for (int i = 0; i < N-2; ++i)
		{
			if (!(s&mask)) best = min(best, dfs(s|mask));
			mask<<=1;
		}
		mask = (1<<N-2)|(1<<N-1)|1;
		if (!(s&mask)) best = min(best, dfs(s|mask));
		mask = (1<<N-1)|1|2;
		if (!(s&mask)) best = min(best, dfs(s|mask));
	}
	return f[s] = best+d;
}

int main()
{
	memset(f, 255, sizeof(f));
	scanf("%d", &N);
	sta = 1<<N;
	for (int i = 0; i < N; ++i)
		scanf("%d", dmg+i);
	f[sta-1] = 0;
	printf("%d\n", dfs(0));
	return 0;
}
