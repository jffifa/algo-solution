/*
	Problem: Ural1060
	Algorithm: Search
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 100;

int Ans, AnsTmp;
char In[6][6], Opr[6][6], Fin[6][6];

void Check()
{
	AnsTmp = 0;
	for (int r = 1; r <= 4; ++r)
		for (int c = 1; c <= 4; ++c)
			Fin[r][c] = In[r][c];
	for (int r = 1; r <= 4; ++r)
		for (int c = 1; c <= 4; ++c)
		{
			Fin[r][c] ^=  Opr[r][c];
			Fin[r+1][c] ^= Opr[r][c];
			Fin[r-1][c] ^= Opr[r][c];
			Fin[r][c+1] ^= Opr[r][c];
			Fin[r][c-1] ^= Opr[r][c];
			AnsTmp += Opr[r][c];
		}
	bool B = 1, W = 1;
	for (int r = 1; r <= 4; ++r)
		for (int c = 1; c <= 4; ++c)
			if (Fin[r][c]) W = 0;
			else B = 0;
	if (B || W)
		Ans = min(Ans, AnsTmp);
}

void Search(int r, int c)
{
	if (r > 4) {Check(); return;}
	if (c > 4) {Search(r+1, 1); return;}
	Opr[r][c] = 0;
	Search(r, c+1);
	Opr[r][c] = 1;
	Search(r, c+1);
}

int main()
{
	//freopen("flip.in", "r", stdin);
	for (int r = 1; r <= 4; ++r)
	{
		for (int c = 1; c <= 4; ++c)
		{
			scanf("%c", &In[r][c]);
			if (In[r][c] == 'w') In[r][c] = 0;
			else In[r][c] = 1;
		}
		scanf("\n");
	}
	Ans = INF;
	Search(1, 1);
	if (Ans == INF) printf("Impossible\n");
	else printf("%d\n", Ans);
	return 0;
}