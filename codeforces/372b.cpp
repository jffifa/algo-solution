#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, Q;
char m[44][44];
int f[44][44][44][44], prev[44][44];

int main() {
    int i, j, x, y;
    cin>>N>>M>>Q;
    for (i = 1; i <= N; ++i)
        scanf("%s", m[i]+1);
    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= M; ++j) {
            if (m[i][j]=='1')
                prev[i][j] = j;
            else
                prev[i][j] = prev[i][j-1];
            //printf("%d ", prev[i][j]);
        }
        //puts("");
    }
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= M; ++j)
            for (x = i; x <= N; ++x)
                for (y = j; y <= M; ++y) {
                    f[i][j][x][y] = f[i][j][x-1][y]+f[i][j][x][y-1]-f[i][j][x-1][y-1];
                    //if (i==1&&j==1&&x==1&&y==3) printf("%d\n", f[i][j][x][y]);
                    int now = j-1;
                    for (int k = x; k >= i; k--) {
                        now = max(now, prev[k][y]);
                        f[i][j][x][y] += y-now;
                    }
                }
    while (Q--) {
        scanf("%d%d%d%d", &i, &j, &x, &y);
        printf("%d\n", f[i][j][x][y]);
    }
    return 0;
}
