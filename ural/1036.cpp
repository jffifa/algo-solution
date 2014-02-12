/*
	Problem: Ural1036
	Algorithm: DP, High Precesion
	Time: O(10N)
	Memory: O()
	Detail: 
	Coded by Biribiri
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXLEN = 100;

struct SHP
{
	int len; unsigned char d[MAXLEN];
	SHP() {len = 1; memset(d, 0, sizeof(d));}
	void Print()
	{
		for (int i = len-1; i >= 0; --i) printf("%d", d[i]);
	}
};

SHP operator + (const SHP &N1, const SHP &N2)
{
	SHP Res;
	Res.len = max(N1.len, N2.len);
	for (int i = 0; i < Res.len; ++i)
	{
		Res.d[i] += N1.d[i]+N2.d[i];
		if (Res.d[i] >= 10)
		{
			++Res.d[i+1];
			Res.d[i] -= 10;
		}
	}
	if (Res.d[Res.len]) ++Res.len;
	return Res;
}

SHP operator += (SHP &N1, const SHP &N2)
{
	N1 = N1+N2;
	return N1;
}

SHP operator * (const SHP &N1, const SHP &N2)
{
	SHP Res;
	Res.len = N1.len+N2.len-1;
	for (int i = 0; i < N1.len; ++i)
		for (int j = 0; j < N2.len; ++j)
		{
			Res.d[i+j] += N1.d[i]*N2.d[j];
			if (Res.d[i+j] >= 10)
			{
				Res.d[i+j+1] += Res.d[i+j]/10;
				Res.d[i+j] %= 10;
			}
		}
	if (Res.d[Res.len]) ++Res.len;
	return Res;
}

const int MAXN = 50;
const int MAXS = 450;

int N, S;
SHP F[MAXN+1][MAXS+1];
SHP Ans;

int main()
{
	scanf("%d%d", &N, &S);
	if (S&1)
	{
		printf("0\n");
		return 0;
	}
	S >>= 1;
	if (S>N*9)
	{
		printf("0\n");
		return 0;
	}
	F[0][0].d[0] = 1;
	F[0][0].len = 1;
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j <= min(i*9, S); ++j)
			for (int k = j; k>=j-9 && k>=0; --k)
				F[i][j] += F[i-1][k];
	Ans = F[N][S]*F[N][S];
	Ans.Print();
	printf("\n");
	return 0;
}
