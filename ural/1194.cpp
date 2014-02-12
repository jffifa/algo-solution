#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;

int main()
{
	cin>>N>>K;
	printf("%d\n", N*(N-1)/2-K);
	return 0;
}
