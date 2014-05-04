/*
    Problem: HDOJ2222
    Algorithm: AC Automation
    Time: O()
    Memory: O()
    Detail: Template Test
    Coded by [BUPT]AkemiHomura
*/

#include <cstring>
#include <cstdio>
using namespace std;

const int MaxNode = 250000;
const int MaxQ = 250000;

struct STrieNode
{
    int cnt;
    STrieNode *c[26];
    //matching failure pointer
    STrieNode *f;
    //id >= 0 means the word exist
    void Init()
    {
        cnt = 0;
        memset(c, 0, sizeof(c));
        f = 0;
    }
    STrieNode()
    {Init();}
};
STrieNode TrieNode[MaxNode];
int NodeNum;
STrieNode *Q[MaxQ]; int Head, Tail;

struct STrie
{
    STrieNode *R;
    void Init()
    {
        R = NULL;
        for (int i = 0; i < NodeNum; ++i)
            TrieNode[i].Init();
        NodeNum = 0;
        R = &TrieNode[NodeNum++];
    }
    STrie()
    {Init();}
    //return the node of string Str
    STrieNode* Insert(char *Str)
    {
        STrieNode *r = R;
        char ch;
        for (int i = 0; Str[i]; ++i)
        {
            ch = Str[i]-'a';
            if (r->c[ch] == NULL)
                r->c[ch] = &TrieNode[NodeNum++];
            r = r->c[ch];
        }
        r->cnt++;
        return r;
    }
    void AhoCorasick()
    {
        Head = Tail = 0;
        R->f = R;
        for (char ch = 0; ch < 26; ++ch)
            if (R->c[ch])
            {
                R->c[ch]->f = R;
                Q[Tail++] = R->c[ch];
            }
            else
                R->c[ch] = R;
        STrieNode *p;
        while (Head != Tail)
        {
            p = Q[Head++]; if (Head >= MaxQ) Head -= MaxQ;
            for (char ch = 0; ch < 26; ++ch)
                if (p->c[ch])
                {
                    p->c[ch]->f = p->f->c[ch];
                    Q[Tail++] = p->c[ch]; if (Tail >= MaxQ) Tail -= MaxQ;
                }
                else
                    p->c[ch] = p->f->c[ch];
        }
    }
    //Sample Function
    //return how many patterns appear in Str
    int Query(char *Str)
    {
        int Ans = 0;
        STrieNode *p = R, *Tmp;
        for (int i = 0; Str[i]; ++i)
        {
            p = p->c[Str[i]-'a'];
            Tmp = p;
            while (Tmp!=R && Tmp->cnt!=-1)
            {
                Ans += Tmp->cnt;
                Tmp->cnt = -1;
                Tmp = Tmp->f;
            }
        }
        return Ans;
    }
};
STrie Trie;

int T, N;
char Ptn[52];
char Str[1000002];

int main()
{
    //freopen("data.in", "r", stdin);
    scanf("%d", &T);
    while (T--)
    {
        Trie.Init();
        scanf("%d", &N);
        while (N--)
        {
            scanf("%s", Ptn);
            Trie.Insert(Ptn);
        }
        Trie.AhoCorasick();
        scanf("%s", Str);
        printf("%d\n", Trie.Query(Str));
    }
    return 0;
}
