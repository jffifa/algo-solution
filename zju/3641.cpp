#include <string>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

set<int> info[111111];
int f[111111];
int id[111111];
int cnt=0;
map<string, int> name;
string s, t;
char op[10];

int find(int x) {
	if (f[x] == -1) return x;
	return f[x] = find(f[x]);
}

void join(int u, int v) {
	int ru = find(u), rv = find(v);
	if (ru==rv) return;
	if (info[ru].size()<info[rv].size()) swap(ru, rv);
	f[rv] = ru;
	for (set<int>::iterator it = info[rv].begin(); it != info[rv].end(); ++it)
		info[ru].insert(*it);
}

int N;

int main() {
	int i, j, k;
	while (cin>>N) {
		cnt = 0;
		name.clear();
		memset(f, -1, sizeof f);
		while (N--) {
			scanf("%s", op);
			if (op[0]=='a') {
				int uid = cnt++;
				id[uid] = uid;
				info[uid].clear();
				cin>>s;
				name[s] = uid;
				scanf("%d", &i);
				while (i--) {
					scanf("%d", &j);
					info[uid].insert(j);
				}
			}
			else if (op[0]=='s') {
				cin>>s>>t;
				join(name[s], name[t]);
			}
			else {
				cin>>s;
				//printf("#%d\n", find(name[s]));
				printf("%d\n", info[find(name[s])].size());
			}
		}
	}
	return 0;
}
