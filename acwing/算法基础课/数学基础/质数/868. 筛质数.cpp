#include<iostream>
using namespace std;

int n;
int ans = 0;
bool visited[1000010];

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if(visited[i] == false)
        {
            ans++;
            for (int j = i; j <= n; j = j + i)
                visited[j] = true;
        }
    }

    cout << ans << endl;
    return 0;
}