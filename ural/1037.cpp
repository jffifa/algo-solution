/*
	Problem: Ural1037
	Algorithm: Heap
	Time: O()
	Memory: O()
	Detail: 
	Coded by [BUPT]AkemiHomura
*/

#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int MaxN = 30000;

//The Minimum Heap
//The comparing function Cmp(x, y)==true iff x < y
template <class T, bool (*Cmp) (const T &, const T &)>
struct SHeap
{
//Data
	//The source array. Index start from 1.
	T *Arr;
	//HeapSize
	int Size;
	//The map contains the indexes of the source array, not the keys. Map[i]->Arr[Map[i]]
	int Map[MaxN+1];
	//The inverse map from the heap to the source array. Arr[i]->Heap[InvMap[i]]
	int InvMap[MaxN+1];

//Function
	inline void Swap(int a, int b)
	{int Tmp=Map[a]; Map[a]=Map[b]; Map[b]=Tmp; InvMap[Map[a]]=a; InvMap[Map[b]]=b;}

	SHeap(T *a, int N = 0)
	{
		Arr = a;
		Size = N;
		for (int i = 1; i <= Size; ++i)
		{
			Map[i] = i;
			InvMap[i] = i;
		}
		for (int i = Size>>1; i >= 1; --i)
			Sink(i);
	}

	void Sink(int i)
	{
		int L, R, Min;
		while (L = i<<1, R = (i<<1)+1, L <= Size)
		{
			Min = i;
			if (L<=Size && Cmp(Arr[Map[L]], Arr[Map[Min]]))
				Min = L;
			if (R<=Size && Cmp(Arr[Map[R]], Arr[Map[Min]]))
				Min = R;
			if (Min == i) break;
			Swap(i, Min);
			i = Min;
		}
	}

	void Rise(int i)
	{
		int P;
		while (i > 1)
		{
			P = i >> 1;
			if (Cmp(Arr[Map[P]], Arr[Map[i]])) break;
			Swap(i, P);
			i = P;
		}
	}

	//i is the index of the source array
	void Insert(int i)
	{
		Map[++Size] = i;
		InvMap[i] = Size;
		Rise(Size);
	}

	//i is the index of the source array
	void Delete(int i)
	{
		int n = InvMap[i];
		Swap(n, Size--);
		Sink(n);
		Rise(n);
	}

	//Delete the top element of the heap
	void Pop()
	{
		//if (Size < 1) throw "ERR: HeapSize == 0!"
		//else
		Delete(Map[1]);
	}

	//i is the index of the source array
	//Arr[i] = x, and then heapify
	void Modify(int i, T x)
	{
		Arr[i] = x;
		Sink(InvMap[i]);
		Rise(InvMap[i]);
	}

	//return the index of the top element of the heap
	int TopIndex()
	{
		//if (Size < 1) throw "ERR: HeapSize == 0!"
		//else
		return Map[1];
	}

	//return the top element of the heap
	T& Top()
	{
		//if (Size < 1) throw "ERR: HeapSize == 0!"
		//else
		return Arr[Map[1]];
	}
};

bool CmpMin(const int &x, const int &y)
{return x < y;}

const int RlsTime = 600;
int Time, BlockNo, Rls, Alc;
char Op;
int FreeNo[MaxN+1], AccTime[MaxN+1];

int main()
{
	//freopen("data.in", "r", stdin);
	for (int i = 1; i <= MaxN; ++i)
		FreeNo[i] = i;
	SHeap<int, CmpMin> Acc(AccTime, 0);
	SHeap<int, CmpMin> Free(FreeNo, MaxN);
	while (~scanf("%d", &Time))
	{
		while (Acc.Size>0 && Time-Acc.Top()>=600)
		{
			Rls = Acc.TopIndex();
			Acc.Pop();
			FreeNo[Rls] = Rls;
			Free.Insert(Rls);
		}
		scanf(" %c", &Op);
		if (Op == '+')
		{
			Alc = Free.Top();//==Free.TopIndex()
			FreeNo[Alc] = -1;
			Free.Pop();
			AccTime[Alc] = Time;
			Acc.Insert(Alc);
			printf("%d\n", Alc);
		}
		else
		{
			scanf(" %d", &BlockNo);
			if (FreeNo[BlockNo] >= 0)
				printf("-\n");
			else
			{
				Acc.Modify(BlockNo, Time);
				printf("+\n");
			}
		}
		scanf("\n");
	}
	return 0;
}
