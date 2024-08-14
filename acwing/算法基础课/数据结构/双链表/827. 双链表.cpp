#include <iostream>
using namespace std;

int n;
int l[100010];
int r[100010];
int e[100010];
int idx = 2;

void insert_left(int x)
{
    e[idx] = x;
    l[idx] = 0;
    r[idx] = r[0];
    l[r[0]] = idx;
    r[0] = idx;
    idx++;
}

void insert_right(int x)
{
    e[idx] = x;
    r[idx] = 1;
    l[idx] = l[1];
    r[l[1]] = idx;
    l[1] = idx;
    idx++;
}

void del(int k)
{
    k = k + 1;
    int left = l[k];
    int right = r[k];
    r[left] = right;
    l[right] = left;
}

void insert_k_left(int k, int x)
{
    k = k + 1;
    int left = l[k];
    e[idx] = x;
    l[idx] = left;
    r[idx] = k;
    r[left] = idx;
    l[k] = idx;
    idx++;
}

void insert_k_right(int k, int x)
{
    k = k + 1;
    int right = r[k];
    e[idx] = x;
    l[idx] = k;
    r[idx] = right;
    l[right] = idx;
    r[k] = idx;
    idx++;
}

int main()
{
    r[0] = 1;
    l[1] = 0;
    int n;
    cin >> n;
    while (n--)
    {
        string command;
        int x, k;
        cin >> command;
        if (command == "L")
        {
            cin >> x;
            insert_left(x);
        }
        else if (command == "R")
        {
            cin >> x;
            insert_right(x);
        }
        else if (command == "D")
        {
            cin >> k;
            del(k);
        }
        else if (command == "IL")
        {
            cin >> k >> x;
            insert_k_left(k, x);
        }
        else
        {
            cin >> k >> x;
            insert_k_right(k, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
    {
        cout << e[i] << " ";
    }
    return 0;
}