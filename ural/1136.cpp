#include <iostream>
using namespace std;

int N;
int postOdr[3333];

struct Node {
    int id;
    Node *left, *right;
};

Node* Build(int l, int r)
{
    if (l > r) return nullptr;

    int pivot = postOdr[r];
    Node* node = new Node();
    node->id = pivot;

    int i = l;
    for (; postOdr[i] < pivot; ++i);
    node->left = Build(l, i - 1);
    node->right = Build(i, r - 1);

    return node;
}

void Print(Node* p)
{
    if (p == nullptr) return;
    Print(p->right);
    Print(p->left);
    printf("%d\n", p->id);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> postOdr[i];
    }

    Node *root = Build(0, N - 1);
    Print(root);
    return 0;
}
