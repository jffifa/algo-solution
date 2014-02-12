/*
	Problem: Ural1055
	Algorithm: Maths
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 50000;
const int Reimu = 8000;

int N, M, R;
int Prime[Reimu], PNum, Ans[Reimu], Kyouko;

void Madoka()
{
	Prime[PNum++] = 2;
	bool P;
	int UB;
	for (int i = 3; i <= MaxN; ++i)
	{
		P = 1;
		UB = (int)sqrt((double)i);
		for (int j = 0; j<PNum && Prime[j]<=UB; ++j)
			if (i % Prime[j] == 0)
			{
				P = 0;
				break;
			}
		if (P) Prime[PNum++] = i;
	}
}

int Homura(int N, int M)
{
	M = min(M, N-M);
	int Mami, j;
	for (int i = N-M+1; i <= N; ++i)
	{
		Mami = i; j = 0;
		while (Mami > 1)
		{
			while (Mami % Prime[j] == 0)
			{
				Ans[j]++;
				Mami /= Prime[j];
			}
			j++;
		}
	}
	for (int i = 1; i <= M; ++i)
	{
		Mami = i; j = 0;
		while (Mami > 1)
		{
			while (Mami % Prime[j] == 0)
			{
				Ans[j]--;
				Mami /= Prime[j];
			}
			j++;
		}
	}
	for (int i = 0; i < Reimu; ++i)
		if (Ans[i]) Kyouko++;
	return Kyouko;
}

int main()
{
	Madoka();
	scanf("%d%d", &N, &M);
	printf("%d\n", Homura(N, M));
	return 0;
}
