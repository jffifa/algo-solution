/*
	Problem: Ural1149
	Algorithm: None
	Time: O()
	Memory: O()
	Detail: Simple
	Coded by [BUPT]AkemiHomura
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

int N;
char Tmp[5];

string itoa(int v)
{
	string str;
	if (v == 0) return str+='0';
	while (v)
	{
		str = (char)(v%10+'0')+str;
		v = v/10;
	}
	return str;
}

string GetA(int i, int n)
{
	string Res;
	if (i == n+1) return Res;
	Res += "sin(";
	Res += itoa(i);
	if (i < n) Res += (i&1) ? '-' : '+';
	Res += GetA(i+1, n);
	Res += ')';
	return Res;
}

string GetS(int i)
{
	string Res;
	if (i == 0) return Res;
	if (i > 1) Res = '('+Res;
	Res += GetS(i-1);
	if (i > 1) Res += ')';
	Res += GetA(1, i);
	Res += '+';
	Res += itoa(N+1-i);
	return Res;
}

int main()
{
	scanf("%d", &N);
	cout << GetS(N) << endl;
	return 0;
}
