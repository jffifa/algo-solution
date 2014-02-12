#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int SIZE = 30;
const LL MOD = 10000007LL;

int N, M, P, R;

struct sm
{
	LL m[SIZE][SIZE];
	void init() {memset(m, 0, sizeof(m));}
	sm() {init();}
	void eye() {init(); for (int i = 0; i < SIZE; ++i) m[i][i] = 1;}
};

sm operator*(const sm &a, const sm &b)
{
	sm res;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				res.m[i][j] = (res.m[i][j]+a.m[i][k]*b.m[k][j]) % MOD;
	return res;
}

sm operator^(sm a, int p)
{
	sm res;
	res.eye();
	for (; p; p >>=1)
	{
		if (p&1)
			res = res*a;
		a = a*a;
	}
	return res;
}

LL x[SIZE];
LL ans[SIZE];
sm tr[30];
sm fin;
char opr[30];
int hmr, mdk, syk, kyk;

int main()
{
	int i, j, k;
	while (~scanf("%d", &N))
	{
		for (i = 0; i < N; ++i)
			scanf("%lld", x+i);
		scanf("%d", &M);
		for (i = 0; i < M; ++i)
		{
			tr[i].eye();
			scanf("%s", opr);
			switch (opr[0])
			{
			case 'r':
				scanf("%d", &hmr);
				hmr--;
				tr[i].m[hmr][hmr] = 0;
			break;
			case 'd':
				scanf("%d", &hmr);
				hmr--;
				tr[i].m[hmr][hmr] = 2;
			break;
			case 'a':
				scanf("%d%d", &hmr, &mdk);
				hmr--; mdk--;
				if (hmr==mdk)
					tr[i].m[hmr][mdk] = 2;
				else
					tr[i].m[hmr][mdk] = 1;
			break;
			case 's':
				scanf("%d%d", &hmr, &mdk);
				hmr--; mdk--;
				tr[i].m[hmr][hmr] = tr[i].m[mdk][mdk] = 0;
				tr[i].m[hmr][mdk] = tr[i].m[mdk][hmr] = 1;
			break;
			case 'i':
				scanf("%d%d", &hmr, &mdk);
				hmr--; mdk--;
				if (hmr>mdk) swap(hmr, mdk);
				for (j = 0; j <= mdk-hmr; ++j)
				{
					tr[i].m[hmr+j][hmr+j] = 0;
					tr[i].m[hmr+j][mdk-j] = 1;
				}
			break;
			case 't':
				scanf("%d%d%d%d", &syk, &hmr, &kyk, &mdk);
				hmr--; mdk--;
				tr[i].m[hmr][hmr] = syk;
				tr[i].m[hmr][mdk] = kyk;
				tr[i].m[mdk][mdk] = 0;
			break;
			}
		}
		tr[M].eye();
		for (i = 0; i < M; ++i)
			tr[M] = tr[i]*tr[M];
		scanf("%d", &P);
		R = P%M;
		P = P/M;
		fin.eye();
		fin = tr[M]^P;
		for (i = 0; i < R; ++i)
			fin = tr[i]*fin;
		/*
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < N; ++j)
				printf("%lld ", fin.m[i][j]);
			puts("");
		}
		*/
		memset(ans, 0, sizeof(ans));
		for (i = 0; i < N; ++i)
			for (j = 0; j < N; ++j)
				ans[i] = (ans[i]+fin.m[i][j]*x[j])%MOD;
		for (i = 0; i < N; ++i)
		{
			if (i) putchar(' ');
			printf("%lld", ans[i]);
		}
		puts("");
	}
	return 0;
}
