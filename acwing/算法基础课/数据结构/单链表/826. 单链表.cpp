#include <iostream>
using namespace std;

int e[100010];
int ne[100010];
int h = -1;
int idx = 1;
int n;

void insert_head(int x)
{
    e[idx] = x;
    ne[idx] = h;
    h = idx;
    idx++;
}

void del(int k)
{
    if(k == 0)
    {
        h = ne[h];
        return;
    }
    int temp = ne[ne[k]];
    ne[k] = temp;
}

void insert_k(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

int main()
{
    cin >> n;
    while (n--)
    {
        char command;
        cin >> command;
        if (command == 'H')
        {
            int x;
            cin >> x;
            insert_head(x);
        }
        else if (command == 'D')
        {
            int k;
            cin >> k;
            del(k);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            insert_k(k, x);
        }
    }

    for (int i = h; i != -1; i = ne[i])
    {
        cout << e[i] << " ";
    }
    return 0;
}