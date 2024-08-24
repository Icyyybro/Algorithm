#include <iostream>
using namespace std;

int board[11][11];
int colum[11];
int left_to_right[50];
int right_to_left[50];
int n;

bool judge(int x, int y)
{
    if (left_to_right[n + x - y] > 0)
        return false;
    if (right_to_left[x + y] > 0)
        return false;
    if (colum[y] > 0)
        return false;
    return true;
}

void add(int x, int y)
{
    left_to_right[n + x - y]++;
    right_to_left[x + y]++;
    colum[y]++;
}

void reset(int x, int y)
{
    left_to_right[n + x - y]--;
    right_to_left[x + y]--;
    colum[y]--;
}

void print_board()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i][j] == 1)
                cout << "Q";
            else
                cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int x)
{
    if (x > n)
    {
        print_board();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (judge(x, i) == true)
        {
            board[x][i] = 1;
            add(x, i);
            dfs(x + 1);
            reset(x, i);
            board[x][i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
}