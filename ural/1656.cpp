#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

int N;
int h[100];
int sqr[10][10];

struct spos
{int r, c, d;}pos[100];
bool operator<(const spos &p1, const spos &p2)
{return p1.d<p2.d;}
/*
int abs(int x)
{return x>0?x:-x;}
*/
int dis(int r, int c)
{return abs(N/2-r)+abs(N/2-c);}

int main()
{
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N*N; ++i)
		scanf("%d", h+i);
	sort(h, h+N*N);
	reverse(h, h+N*N);
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
		{
			pos[i*N+j].r = i;
			pos[i*N+j].c = j;
			pos[i*N+j].d = dis(i, j);
		}
	sort(pos, pos+N*N);
	for (i = 0; i < N*N; ++i)
		sqr[pos[i].r][pos[i].c] = h[i];
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (j) putchar(' ');
			printf("%d", sqr[i][j]);
		}
		puts("");
	}
	return 0;
}
