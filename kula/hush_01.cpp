#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 22;

bool vis[MAX][MAX];
vector<vector<int> > f[MAX][MAX];

vector<vector<int> > solve(int n, int m) {
    if (vis[n][m]) return f[n][m];
    vis[n][m] = true;
    f[n][m] = solve(n, m-1);
    if (m <= (n+1)/2) {
        vector<vector<int> > tmp = solve(n-m, m);
        for (vector<vector<int> >::iterator it = tmp.begin(); it != tmp.end(); ++it) {
            it->push_back(m);
            f[n][m].push_back(*it);
        }
    }
    return f[n][m];
}

void print(const vector<vector<int> > &ans) {
    for (vector<vector<int> >::const_iterator it = ans.begin(); it != ans.end(); ++it) {
        for (vector<int>::const_iterator jt = it->begin(); jt != it->end(); ++jt) {
            printf("%d ", *jt);
        }
        puts("");
    }
}

void print(int n, int m, vector<int> &ans) {
    if (m==0) {
        if (n==0) {
            for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
                printf("%d ", *it);
            }
            puts("");
        }
        return;
    }
    print(n, m-1, ans);
    if (m <= (n+1)/2) {
        ans.push_back(m);
        print(n-m, m, ans);
        ans.pop_back();
    }
    return;
}

int main() {
    int N;
    for (int i = 0; i < MAX; ++i)
        vis[i][0] = true;
    f[0][0].push_back(vector<int>());
    while (cin>>N) {
        solve(N, N);
        print(f[N][N]);

        //another way
        vector<int> ans;
        print(N, N, ans);
    }
    return 0;
}
