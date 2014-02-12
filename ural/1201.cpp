#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int zeller(int y, int m, int d)
{
	if (m <= 2)
	{
		y--;
		m += 12;
	}
	int c = y/100;
	y %= 100;
	int w = (c/4-2*c+y+y/4+13*(m+1)/5+d-1) % 7;
	if (w < 0) w += 7;
	return w;
}

bool hmr(int y)
{
	if (y%100==0)
		return y%400==0;
	return y%4==0;
}

int y, m, d, dn;
int first[8], last[8];
int mdk[32];
string str[8];
char strtmp[4];
char weekstr[8][5] = {"hmr", "mon", "tue", "wed", "thu", "fri", "sat", "sun"};

int daynum(int y, int m)
{
	if (m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		return 31;
	if (m==4||m==6||m==9||m==11)
		return 30;
	if (hmr(y)) return 29;
	else return 28;
}

int main()
{
	scanf("%d%d%d", &d, &m, &y);
	for (int w = 1; w <= 7; ++w)
	{
		first[w] = 999;
		last[w] = 0;
	}
	dn = daynum(y, m);
	for (int t = 1; t <= dn; ++t)
	{
		int w = zeller(y, m, t); if (!w) w += 7;
		first[w] = min(first[w], t);
		last[w] = max(last[w], t);
		mdk[t] = w;
		str[w] += ' ';
		str[w] += (t==d?'[':' ');
		if (t/10==0) str[w] +=' ';
		memset(strtmp, 0, sizeof(strtmp));
		sprintf(strtmp, "%d", t);
		str[w] += strtmp;
		str[w] += (t==d?']':' ');
	}
	for (int w = 1; w <= 7; ++w)
	{
		if (mdk[first[w]] < mdk[1]) str[w] = "     "+str[w];
		if (mdk[last[w]] > mdk[dn]) str[w] = str[w]+"     ";
		str[w] = weekstr[w]+str[w];
		while (str[w][str[w].length()-1]==' ')
			str[w].erase(str[w].end()-1);
		cout << str[w] << endl;
	}
	return 0;
}	
