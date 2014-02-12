/*
	Problem: Ural1035
	Algorithm: Graph, Euler Path
	Time: O(N)
	Memory: O()
	Detail: 
	Coded by Biribiri
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int MaxN = 40404;

int R, C, Tmp, Ans;
int Deg[2][MaxN];
char Ch;
vector<int> G[MaxN];
bool Vis[MaxN];

int DFS(int v)
{
	if (Vis[v]) return 0;
	Vis[v] = 1;
	int Res = abs(Deg[0][v]-Deg[1][v]);
	for (int i = 0; i < G[v].size(); ++i)
		Res += DFS(G[v][i]);
	return Res;
}

int main()
{
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	scanf("%d%d\n", &R, &C);
	for (int i = 0; i < 2; ++i)
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				scanf("%c", &Ch);
				if (Ch == '\\')
				{
					G[r*(C+1)+c].push_back((r+1)*(C+1)+c+1);
					++Deg[i][r*(C+1)+c];
					G[(r+1)*(C+1)+c+1].push_back(r*(C+1)+c);
					++Deg[i][(r+1)*(C+1)+c+1];
				}
				else if (Ch == '/')
				{
					G[r*(C+1)+c+1].push_back((r+1)*(C+1)+c);
					++Deg[i][r*(C+1)+c+1];
					G[(r+1)*(C+1)+c].push_back(r*(C+1)+c+1);
					++Deg[i][(r+1)*(C+1)+c];
				}
				else if (Ch == 'X')
				{
					G[r*(C+1)+c].push_back((r+1)*(C+1)+c+1);
					++Deg[i][r*(C+1)+c];
					G[(r+1)*(C+1)+c+1].push_back(r*(C+1)+c);
					++Deg[i][(r+1)*(C+1)+c+1];
					G[r*(C+1)+c+1].push_back((r+1)*(C+1)+c);
					++Deg[i][r*(C+1)+c+1];
					G[(r+1)*(C+1)+c].push_back(r*(C+1)+c+1);
					++Deg[i][(r+1)*(C+1)+c];
				}
			}
			scanf("\n");
		}
	for (int r = 0; r <= R; ++r)
		for (int c = 0; c <= C; ++c)
			if (!Vis[r*(C+1)+c] && G[r*(C+1)+c].size())
			{
				Tmp = DFS(r*(C+1)+c);
				if (Tmp == 0) Ans += 1;
				else Ans += Tmp/2;
			}
	printf("%d\n", Ans);
	return 0;
}
