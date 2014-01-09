/*
 * Description:
 *   Find all the partitions S of the given integer n, (sum of S is n)
 *   that S satisfies the following condition:
 *   for all integer x, 1<=x<=n, there is at least one subset of S, whose sum is x.
 *
 * From:
 *   hush
 *
 * Solution(in Chinese):
 *   令F[n][m]表示所有和为n，且S中最大数不超m的解集。
 *   有F[n][m] = F[n][m-1], m>n/2
 *             = F[n][m-1] 并 { {m}并S' | S'属于F[n-m][m] }
 * 
 * Proof(in Chinese):
 *   考虑解集中最大的数，不妨设为x。
 *   显然x<=n/2（否则剩下数之和小于n/2，于是ceil(n/2)就凑不出来了）
 *
 *   所以F[n][m]，当m>n/2时候就是F[n][m-1]，
 *   当m<=n/2时，分两种情况：最大数是m，最大数不超过m-1的，后者同上。
 *
 *   下面考察对于F[n][m]，最大数是m的情况,设解集为G。我们F[n-m][m]->G是一一对应，
 *   并且映射函数就是F[n-m][m]的每个解后面添上一个m。
 *
 *   先证F[n-m][m]->G是单射：
 *   对于F[n-m][m]中的每个解S'后面添上m，构成S。
 *   由于S'能凑成1,2,..,n-m的每个数，所以S能凑成1,2,..,n-m和m+1,m+2,...,n的每个数，又n-m+1>=m+1，所以S属于G
 *   显然F[n-m][m]中的每个解添上m后，方案是不会重复的。所以F[n-m][m]->G是单射
 *
 *   再证F[n-m][m]->G是满射：
 *   反证法，假设对于G中的某个解S，去掉一个m后（设为S'），不属于F[n-m][m]，或者说S'不能凑成1,2,..,n-m中的某个数。
 *   不妨设不能凑成的最小的数是k，k<n-m。
 *   如果k<m，那么S'即使并上m（变为S），也不能凑成k，于是S不属于G，矛盾。
 *   如果k>=m，那么S'能够凑成1,2,..,k-1。
 *
 */
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
