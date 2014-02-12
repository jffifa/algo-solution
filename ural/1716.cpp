#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 2502;

int N, S, P, Q;
double f[2][MAX][2];
//double f[MAX*MAX][2];

int main() {
	int i, j, k;
	cin>>N>>S;
	P = S-N*2;
	Q = N-P;
	//printf("%d %d\n", P, Q);
	printf("%.6f\n", Q+Q*(P-Q+1.0)/(P+Q));
	/*
	f[1][0][0] = 0;
	f[0][1][1] = 1;
	for (i = 0; i <= P; ++i)
		for (j = 0; j <= Q; ++j) {
			if (i+j<2) continue;
			if (i) f[i][j][0] = f[i-1][j][0]*(i-1)/(i-1+j)+f[i-1][j][1]*j/(i-1+j);
			if (j) f[i][j][1] = (f[i][j-1][0]+2)*i/(i+j-1)+f[i][j-1][1]*(j-1)/(i+j-1);
			//printf("%d %d %f %f\n", i, j, f[i][j][0], f[i][j][1]);
		}
	printf("%.6f\n", (P*f[P][Q][0]+Q*f[P][Q][1])/(P+Q));
	*/
	/*
	for (P = 0; P <= 7; ++P) {
		for (Q = 0; Q <= 7; ++Q) {
	int cur = 0, prev = 1;
	f[cur][0][0] = 0;
	f[cur][1][1] = 1;
	for (k = 2; k <= P+Q; ++k) {
		prev = cur;
		cur = 1-cur;
		for (j = 0; j <= Q; ++j) {
			i = k-j;
			f[cur][j][0] = f[cur][j][1] = 0;
			if (i) f[cur][j][0] = f[prev][j][0]*(i-1)/(k-1)+f[prev][j][1]*j/(k-1);
			if (j) f[cur][j][1] = (f[prev][j-1][0]+2)*i/(k-1)+f[prev][j-1][1]*(j-1)/(k-1);
			//printf("%f %f\n", f[cur][j][0], f[cur][j][1]);
		}
	}
	if (P+Q==0) printf("0.000000 "); else
	printf("%04.6f ", (P*f[cur][Q][0]+Q*f[cur][Q][1])/(P+Q));
		}
		puts("");
	}
	*/

	return 0;
}
