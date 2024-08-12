#include <bits/stdc++.h>
using namespace std;

string str1;
vector<int> num1;
deque<int> answer;
int num2;

void merge(string s1)
{
    for (int i = 0; i < s1.size(); i++)
        num1.push_back(s1[i] - '0');
}

void solve()
{
    int i = 0;
    int cnt = 0;
    for (i = 0; i < num1.size(); i++)
    {
        cnt = cnt * 10 + num1[i];
        answer.push_back(cnt / num2);
        cnt = cnt % num2;
    }

    for (int i = 0; i < answer.size() - 1; i++)
    {
        if(answer.front())
            break;
        else
            answer.pop_front();
    }

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i];
    cout << endl;
    cout << cnt << endl;
}

int main()
{
    cin >> str1;
    cin >> num2;
    merge(str1);
    solve();

    return 0;
}