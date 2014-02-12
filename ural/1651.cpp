/*
	Problem: Ural1651
	Algorithm: vertex seperation, dijkstra
	Time: O()
	Memory: O()
	Detail: 
	Coded by Biribiri
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxV = 100010;
const int Inf = 0x0fffffff;

/*
struct SAdjList
{
	int v, dis;
	SAdjList () {}
	SAdjList (int V, int D) {v = V; dis = D;}
};

int V, v;
int f[MaxV], g[MaxV], Prev[MaxV], Dis[MaxV];
vector<SAdjList> Edge[MaxV];
int HeapSize, Heap[MaxV], VtoH[MaxV];
vector<int> Path;

inline void HeapSwap(int a, int b)
{int Tmp=Heap[a]; Heap[a]=Heap[b]; Heap[b]=Tmp; VtoH[Heap[a]]=a; VtoH[Heap[b]]=b;}

void HeapSink(int i)
{
	int L, R, Min;
	while (L = i<<1, R = (i<<1)+1, L <= HeapSize)
	{
		Min = i;
		if (L <= HeapSize && Dis[Heap[L]]<Dis[Heap[Min]])
			Min = L;
		if (R <= HeapSize && Dis[Heap[R]]<Dis[Heap[Min]])
			Min = R;
		if (Min == i) break;
		HeapSwap(i, Min);
		i = Min;
	}
}

void HeapRise(int i)
{
	int P;
	while (i > 1)
	{
		P = i >> 1;
		if (Dis[Heap[i]]>=Dis[Heap[P]]) break;
		HeapSwap(i, P);
		i = P;
	}
}

void HeapInsert(int x)
{
	Heap[++HeapSize] = x;
	HeapRise(HeapSize);
}

int HeapDelete(int i)
{
	int Ans = Heap[i];
	HeapSwap(i, HeapSize--);
	HeapSink(i);
	HeapRise(i);
	return Ans;
}

inline void Relax(int u, int v, int d)
{
	if (Dis[v] > Dis[u]+d)
	{
		Dis[v] = Dis[u]+d;
		HeapRise(VtoH[v]);
		Prev[v] = u;
	}
}

void RelaxU_AdjList(int u)
{
	for (int e = 0; e < Edge[u].size(); ++e)
		Relax(u, Edge[u][e].v, Edge[u][e].dis);
}

int main()
{
	scanf("%d", &V);
	scanf("%d", &v);
	f[v] = 1; g[1] = v;
	for (int i = 2; i <= V; ++i)
	{
		scanf("%d", &v);
		if (f[v])
			Edge[f[v]].push_back(SAdjList(i, 0));
		f[v] = i; g[i] = v;
		Edge[i-1].push_back(SAdjList(i, 1));
	}
	for (int i = 1; i <= V; ++i)
	{
		Dis[i] = Inf;
		Prev[i] = 0;
	}
	Dis[1] = 0;
	HeapSize = V;
	for (int i = 1; i <= HeapSize; ++i)
	{
		Heap[i] = i;
		VtoH[i] = i;
	}
	HeapSwap(1, VtoH[1]);
	while (HeapSize)
	{
		RelaxU_AdjList(Heap[1]);
		HeapDelete(1);
	}
	v = V;
	while (v)
	{
		if (!Path.size() || g[v] != Path[Path.size()-1]) Path.push_back(g[v]);
		v = Prev[v];
	}
	reverse(Path.begin(), Path.end());
	for (int i = 0; i < Path.size()-1; ++i)
		printf("%d ", Path[i]);
	printf("%d\n", Path[Path.size()-1]);
	return 0;
}
*/

int V, v;
int f[MaxV], g[MaxV], Prev[MaxV], Dis[MaxV];
vector<int> Path;

int main()
{
	scanf("%d", &V);
	scanf("%d", &v);
	for (int i = 1; i <= V; ++i)
	{
		Dis[i] = Inf;
		Prev[i] = 0;
	}
	f[v] = 1; g[1] = v; Prev[1] = 0; Dis[1] = 0;
	for (int i = 2; i <= V; ++i)
	{
		scanf("%d", &v);
		if (f[v])
		{
			Dis[i] = Dis[f[v]];
			Prev[i] = f[v];
		}
		f[v] = i; g[i] = v;
		if (Dis[i-1]+1 < Dis[i])
		{
			Dis[i] = Dis[i-1]+1;
			Prev[i] = i-1;
		}
	}
	v = V;
	while (v)
	{
		if (!Path.size() || g[v] != Path[Path.size()-1]) Path.push_back(g[v]);
		v = Prev[v];
	}
	reverse(Path.begin(), Path.end());
	for (int i = 0; i < Path.size()-1; ++i)
		printf("%d ", Path[i]);
	printf("%d\n", Path[Path.size()-1]);
	return 0;
}
