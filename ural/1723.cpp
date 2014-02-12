#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int len;
string s;
string ans;
map<string, int> hmr;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); ++i)
		for (int j = i; j < s.length(); ++j)
			++hmr[s.substr(i, j-i+1)];
	map<string, int>::iterator it;
	len = 0;
	for (it = hmr.begin(); it != hmr.end(); ++it)
		if (it->second>len)
		{
			len = it->second;
			ans = it->first;
		}
	cout << ans << endl;
	return 0;
}
