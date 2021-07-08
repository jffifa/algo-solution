#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
int NodeCnt = 0; // Node0 for root
map<string, int> subdir[40001];

void ParsePath(const string& path, int& node, int& parsePos)
{
    int startPos = parsePos;
    for (; parsePos != path.length() && path[parsePos] != '\\'; parsePos++);
    string dirname = path.substr(startPos, parsePos - startPos);

    if (subdir[node].find(dirname) == subdir[node].end())
    {
        NodeCnt++;
        subdir[node].insert(make_pair(dirname, NodeCnt));
    }
    node = subdir[node][dirname];

    parsePos++;
}

void Parse(string path)
{
    int node = 0;
    int parsePos = 0;
    while (parsePos < path.length())
    {
        ParsePath(path, node, parsePos);
    }
}

void Print(int node, int depth)
{
    for (const auto& it : subdir[node])
    {
        for (int i = 0; i < depth; ++i)
            printf(" ");
        printf("%s\n", it.first.c_str());
        Print(it.second, depth + 1);
    }
}

int main()
{
    string path;
    cin >> N;
    while (N--)
    {
        cin >> path;
        Parse(path);
    }
    Print(0, 0);
}
