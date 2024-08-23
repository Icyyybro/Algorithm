#include <iostream>
using namespace std;

int n, m;
char command;
int f[100010];

int find(int x)
{
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

void insert(int a, int b)
{
    int f_a = find(a);
    int f_b = find(b);
    if (f_a == f_b)
        return;
    else
        f[f_a] = f_b;
}

bool judge(int a, int b)
{
    int f_a = find(a);
    int f_b = find(b);
    if (f_a == f_b)
        return true;
    else
        return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        f[i] = i;

    while (m--)
    {
        int a, b;
        cin >> command >> a >> b;
        if (command == 'M')
            insert(a, b);
        else
        {
            if (judge(a, b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}