#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int S = 303*303*2;

typedef long long LL;
typedef pair<int, int> pr;
pr (*mkpr)(int, int)=make_pair;


int N, M;
LL ans = 0;
map<int, int> color;
int s[S];
int pan[303][303], sym[303][303];
int colorcnt = 0;
vector<pr> node[S];
queue<pr> q;
pr now;
int snow, cnow, cchg;

inline int getcolor(int x)
{
	if (!color.count(x)) color[x] = colorcnt++;
	return color[x];
}

inline int dis(int i, int j)
{
	int n;
	if (j <= 0) n = max(abs(j), abs(i)-1);
	else n = max(abs(j), abs(i))-1;
	if (i==n+1) return 4*(n+1)*(n+1)+(n+1)-j;
	else if (j==n+1) return (4*n+2)*(n+1)+(n+1)+i;
	else if (i==-n-1) return (2*n+1)*(2*n+1)+n+j;
	else return 4*n*n+2*n+n-i;
}

bool cmp(const pr &u, const pr &v)
{return dis(u.first-now.first, u.second-now.second)<dis(v.first-now.first, v.second-now.second);}

int main()
{
	int i, j, k, x, y;
	scanf("%d%d", &N, &M);
	color[0] = colorcnt++;
	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
		{
			scanf("%d", &pan[i][j]);
			pan[i][j] = getcolor(pan[i][j]);
			s[pan[i][j]]++;
		}
	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
		{
			scanf("%d", &sym[i][j]);
			if (sym[i][j]!=-1) sym[i][j] = getcolor(sym[i][j]);
		}
	scanf("%d%d", &x, &y);
	x--; y--;
	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
			if (i==x&&j==y) q.push(mkpr(i, j));
			else if (sym[i][j]!=-1) node[pan[i][j]].push_back(mkpr(i, j));
	cnow = pan[x][y]; snow = 0;
	while (!q.empty())
	{
		now = q.front(); q.pop();
		i = now.first, j = now.second;
		cchg = sym[i][j];
		if (cnow==0 || cnow==cchg) continue;
		snow += s[cnow];
		s[cnow] = 0;
		ans += snow;
		vector<pr> elm = node[cnow];
		node[cnow].clear();
		sort(elm.begin(), elm.end(), cmp);
		for (k = 0; k < elm.size(); ++k)
			q.push(elm[k]);
		cnow = cchg;
	}
	cout << ans << endl;
}
