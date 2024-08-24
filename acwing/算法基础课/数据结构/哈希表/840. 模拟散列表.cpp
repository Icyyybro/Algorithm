#include <iostream>
using namespace std;
#define N 10003

int n;
int h[100010], e[100010], ne[100010];
int idx = 0;

void insert(int x)
{
    int t = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[t];
    h[t] = idx;
    idx++;
}

bool find(int x)
{
    int t = (x % N + N) % N;
    for (int i = h[t]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i <= N; i++)
        h[i] = -1;
    while (n--)
    {
        char command;
        int x;
        cin >> command;
        cin >> x;
        if (command == 'I')
        {
            insert(x);
        }
        else
        {
            if (find(x))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}