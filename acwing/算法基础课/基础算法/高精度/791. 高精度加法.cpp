#include <bits/stdc++.h>
using namespace std;

vector<int> num1;
vector<int> num2;
string str1;
string str2;

void merge(string s1, string s2)
{
    for (int i = s1.size() - 1; i >= 0; i--)
        num1.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i--)
        num2.push_back(s2[i] - '0');
}

void add()
{
    int cnt = 0;
    int i;
    for (i = 0; i < num2.size(); i++)
    {
        cnt = cnt + num1[i] + num2[i];
        num1[i] = cnt % 10;
        cnt = cnt / 10;
    }
    while (i < num1.size())
    {
        cnt = cnt + num1[i];
        num1[i] = cnt % 10;
        cnt = cnt / 10;
        i++;
    }
    if (cnt)
        num1.push_back(cnt);
}

int main()
{
    cin >> str1;
    cin >> str2;
    if (str1.size() >= str2.size())
        merge(str1, str2);
    else
        merge(str2, str1);
    add();

    for (int i = num1.size() - 1; i >= 0; i--)
        cout << num1[i];
    return 0;
}