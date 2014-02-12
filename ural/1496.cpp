#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int N;
map<string, int> hmr;
set<string> mdk;
string str;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> str;
		if (hmr.count(str)) mdk.insert(str);
		else hmr[str] = i;
	}
	for (set<string>::iterator it = mdk.begin(); it != mdk.end(); ++it)
		cout << *it << endl;
	return 0;
}
