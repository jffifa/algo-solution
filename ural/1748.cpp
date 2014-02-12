/*
	Problem: Ural1748
	Algorithm: Search
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/
#include <cstdio>
#include <cstring>
using namespace std;

typedef unsigned long long ULL;

const int Prime[17] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51};
const int Orz = 100;

ULL N, MaxAP;
int T, MaxFacNum;

void DFS(int i, int FacNum, int MaxPow, ULL AP)
{
	if (FacNum>MaxFacNum || (FacNum==MaxFacNum && AP<MaxAP))
	{
		MaxFacNum = FacNum;
		MaxAP = AP;
	}
	for (int p = 1; p <= MaxPow; ++p)
	{
		if (N/AP < Prime[i]) return;
		AP = AP * (ULL)Prime[i];
		DFS(i+1, FacNum*(p+1), p, AP);
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%llu", &N);
		MaxAP = 0;
		MaxFacNum = 0;
		DFS(1, 1, Orz, 1);
		printf("%llu %d\n", MaxAP, MaxFacNum);
	}
	return 0;
}

