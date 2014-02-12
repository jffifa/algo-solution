#include <iostream>
#include <cstdio>
using namespace std;

int N, R, C;
int a[101];

int main()
{
	int i, j, k;
	cin>>N>>C;
	for (i = 0; i < N; ++i)
		cin>>a[i];
	R = N/C;
	if (N%C) R++;
	for (i = 0; i < R; ++i)
	{
		for (j = 0; j < C; ++j)
			if (j*R+i<N) printf("% 4d", a[j*R+i]);
		puts("");
	}
	return 0;
}
