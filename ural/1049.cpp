/*
	Problem: Ural1049
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by Biribiri
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxP = 9973;

int P[2000], PNum, t, Ans;
vector<int> Div;
vector<int> Pow;

bool Prime(int x)
{
	for (int i = 0; P[i]<=(int)sqrt((double)x); ++i)
		if (x%P[i] == 0) return 0;
	return 1;
}

void Factorize(int x)
{
	int i = 0;
	while (x > 1)
	{
		while (x % P[i] == 0) {Div.push_back(P[i]); x /= P[i];}
		++i;
	}
}

int main()
{
	P[PNum++] = 2;
	P[PNum++] = 3;
	for (int x = 4; x <= MaxP; ++x)
		if (Prime(x)) P[PNum++] = x;
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &t);
		Factorize(t);
	}
	sort(Div.begin(), Div.end());
	t = 0;
	for (int i = 0; i < Div.size(); ++i)
		if (Div[i] != t)
		{
			Pow.push_back(1);
			t = Div[i];
		}
		else
			++Pow[Pow.size()-1];
	Ans = 1;
	for (int i = 0; i < Pow.size(); ++i)
		Ans *= Pow[i]+1;
	printf("%d\n", Ans%10);
	return 0;
}
