#include <iostream>
using namespace std;

int m;
int a[100010];
int top = 0;
int bottom = 0;

void push(int x)
{
    a[top] = x;
    top++;
}

void pop()
{
    top--;
}

bool empty()
{
    if (top == bottom)
        return true;
    else
        return false;
}

int query()
{
    return a[top - 1];
}

int main()
{
    cin >> m;
    while (m--)
    {
        string command;
        int x;
        cin >> command;
        if (command == "push")
        {
            cin >> x;
            push(x);
        }
        else if (command == "pop")
        {
            pop();
        }
        else if (command == "empty")
        {
            if (empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << query() << endl;
        }
    }

    return 0;
}