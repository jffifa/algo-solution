#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define MaxN 250

int N, M, Start, Finish, NewRep;
struct
{
	int Prev, Ending;
} Edge[MaxN * MaxN];
int Head[MaxN], Match[MaxN], Father[MaxN], Rep[MaxN];
bool In_Queue[MaxN], In_Path[MaxN], In_Tree[MaxN];
vector <int> Path, Tree;
deque <int> Queue;

void Insert_Edge(int I, int S, int T)
{
	Edge[I]. Ending = T;
	Edge[I]. Prev = Head[S];
	Head[S] = I;
}

void Push_To_Tree(int U)
{
	if (In_Tree[U]) return;
	In_Tree[U] = 1;
	Tree. push_back(U);
}

void Push(int U)
{
	In_Queue[U] = 1;
	Queue. push_back(U);
	Push_To_Tree(U);
}

int Find_Set(int U)
{
	for (; Rep[U] != U; ) U = Rep[U];
	return U;
}

int Find_Common_Ancestor(int U, int V)
{
	for (; ; )
	{
		U = Find_Set(U);
		Path. push_back(U);
		In_Path[U] = 1;
		if (U == Start) break;
		U = Father[Match[U]];
	}
	for (; ; )
	{
		V = Find_Set(V);
		if (In_Path[V]) break;
		V = Father[Match[V]];
	}
	for (; Path. size(); )
	{
		U = Path. back();
		Path. pop_back();
		In_Path[U] = 0;
	}
	return V;
}

void Reset_Trace(int U)
{
	for (; Find_Set(U) != NewRep; )
	{
		int V = Match[U];
		if (!In_Queue[V]) Push(V);
		if (Rep[U] == U) Rep[U] = NewRep;
		if (Rep[V] == V) Rep[V] = NewRep;
		U = Father[V];
		if (Find_Set(U) != NewRep) Father[U] = V;
	}
}

void Blossom_Contract(int U, int V)
{
	NewRep = Find_Common_Ancestor(U, V);
	if (Find_Set(U) != NewRep) Father[U] = V;
	if (Find_Set(V) != NewRep) Father[V] = U;
	Reset_Trace(U);
	Reset_Trace(V);
}

bool Find_Augmenting_Path()
{
	Queue. clear();
	Queue. push_back(Start);
	for (; !Queue. empty(); )
	{
		int U = Queue. front();
		Queue. pop_front();
		for (int Ptr = Head[U]; Ptr; Ptr = Edge[Ptr]. Prev)
		{
			int V = Edge[Ptr]. Ending;
			if (Find_Set(U) != Find_Set(V) && Match[U] != V)
				if (Match[V] && Father[Match[V]]) Blossom_Contract(U, V);
				else if (!Father[V])
				{
					Father[V] = U;
					Push_To_Tree(V);
					if (Match[V]) Push(Match[V]);
					else {
						Finish = V;
						return 1;
					}
				}
		}
	}
	return 0;
}

void Augment_Path()
{
	for (int U = Finish; U; )
	{
		int V = Father[U], W = Match[V];
		Match[V] = U;
		Match[U] = V;
		U = W;
	}
}

void Clear_Tree()
{
	for (; Tree. size(); )
	{
		int U = Tree. back();
		Tree. pop_back();
		In_Tree[U] = In_Queue[U] = Father[U] = 0;
		Rep[U] = U;
	}
}

void Edmonds()
{
	memset(Match, 0, sizeof(Match));
	memset(Father, 0, sizeof(Father));
	memset(In_Queue, 0, sizeof(In_Queue));
	memset(In_Path, 0, sizeof(In_Path));
	memset(In_Tree, 0, sizeof(In_Tree));
	Path. clear();
	Tree. clear();
	for (int i = 1; i <= N; ++ i)
		Rep[i] = i;
	for (int i = 1; i <= N; ++ i)
		if (!Match[i])
		{
			Start = i;
			if (Find_Augmenting_Path()) Augment_Path();
			Clear_Tree();
		}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Ural1099.in", "r", stdin);
	freopen("Ural1099.out", "w", stdout);
#endif
	scanf("%d", &N);
	int M = 0;
	memset(Head, 0, sizeof(Head));
	for (int U, V; scanf("%d%d", &U, &V) == 2; )
	{
		++ M;
		Insert_Edge(M, U, V);
		++ M;
		Insert_Edge(M, V, U);
	}
	Edmonds();
	int Count = 0;
	for (int i = 1; i <= N; ++ i)
		if (Match[i]) ++ Count;
	printf("%d\n", Count);
	for (int i = 1; i <= N; ++ i)
		if (i < Match[i]) printf("%d %d\n", i, Match[i]);
}
