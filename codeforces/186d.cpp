#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

double s;
int a, b, c;

int main() {
	cin>>s>>a>>b>>c;
	if (a+b+c==0) printf("%.10f 0 0\n", s);
	else printf("%.10f %.10f %.10f\n", s*a/(a+b+c), s*b/(a+b+c), s*c/(a+b+c));
	return 0;
}
