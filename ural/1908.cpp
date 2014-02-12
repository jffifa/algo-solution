#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int INF = 0x3fffffff;

struct snode {
    bool e;
    int f, c[26];
    void init() {
        e = 0;
        f = -1;
        memset(c, -1, sizeof c);
    }
    snode() {init();}
}node[111111];

int N, num;
char s[111111];
int d[111111], f[111111], g[111111], cnt[111111];

void init() {
    num = 0;
    node[num++].init();
    memset(d, 0, sizeof d);
    memset(cnt, 0, sizeof cnt);
}

void insert(char *s) {
    int p = 0;
    int ch;
    for (int i = 0; s[i]; ++i) {
        ch = s[i]-'a';
        if (node[p].c[ch] == -1) {
            ++d[p];
            node[p].c[ch] = num;
            node[num].init();
            node[num++].f = p;
        }
        p = node[p].c[ch];
    }
    node[p].e = 1;
}

void dfs(int u) {
    if (node[u].e) {
        f[u] = g[u] = 0;
        cnt[u] = 1;
        return;
    }
    int sum = 0, i, v;
    cnt[u] = 0;
    for (i = 0; i < 26; ++i) {
        v = node[u].c[i];
        if (v == -1) continue;
        dfs(v);
        cnt[u] += cnt[v];
        sum += f[v]+cnt[v];
    }
    f[u] = g[u] = INF;
    for (i = 0; i < 26; ++i) {
        v = node[u].c[i];
        if (v == -1) continue;
        f[u] = min(f[u], sum-f[v]+g[v]);
        g[u] = min(g[u], sum-f[v]-cnt[v]+g[v]);
    }
}

queue<int> q;

void bfs() {
    int i, j, u, v;
    for (u = 1; u < num; ++u)
        if (node[u].e) q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        --d[node[u].f];
        if (d[node[u].f]==0) q.push(node[u].f);
        if (node[u].e) {
            f[u] = g[u] = 0;
            cnt[u] = 1;
            continue;
        }
        int sum = 0, i, v;
        for (i = 0; i < 26; ++i) {
            v = node[u].c[i];
            if (v == -1) continue;
            cnt[u] += cnt[v];
            sum += f[v]+cnt[v];
        }
        f[u] = g[u] = INF;
        for (i = 0; i < 26; ++i) {
            v = node[u].c[i];
            if (v == -1) continue;
            f[u] = min(f[u], sum-f[v]+g[v]);
            g[u] = min(g[u], sum-f[v]-cnt[v]+g[v]);
        }
    }
}

int main() {
    int i, j, k;
    while (cin>>N) {
        init();
        for (i = 0; i < N; ++i) {
            scanf("%s", s);
            insert(s);
        }
        dfs(0);
        //bfs();
        printf("%d\n", f[0]);
    }
    return 0;
}
