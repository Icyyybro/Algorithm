#include <iostream>
using namespace std;

int n = 1;
int m;
int a[100010];
int e[100010];
int idx = 1;

int value(int x)
{
    return e[a[x]];
}

void down(int x)
{
    int l_child = 2 * x;
    int r_child = 2 * x + 1;
    int pos = x;
    if (l_child <= n && value(l_child) < value(pos))
        pos = l_child;
    if (r_child <= n && value(r_child) < value(pos))
        pos = r_child;
    if (pos != x)
    {
        swap(a[pos], a[x]);
        down(pos);
    }
}

void up(int x)
{
    int father = x / 2;
    int pos = x;
    if (father >= 1 && value(father) > value(x))
        pos = father;
    if (pos != father)
    {
        swap(a[pos], a[father]);
        up(pos);
    }
}

void heap_sort()
{
    for (int i = n / 2; i > 0; i--)
        down(i);
}

void insert(int v)
{
    e[idx] = v;
    a[++n] = idx;
    idx++;
    up(n);
}

void dele(int x)
{
}

int main()
{
    cin >> m;
    while (m--)
    {
        string command;
        int k, x;
        cin >> command;
        if (command == "I")
        {
            cin >> x;
            insert(x);
        }
        else if (command == "PM")
        {
            cout << value(1) << endl;
        }
        else if (command == "DM")
        {
        }
    }
}