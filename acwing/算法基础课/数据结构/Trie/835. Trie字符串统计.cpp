#include<iostream>
using namespace std;

int n;
int a[100010][26];
int idx = 1;
int cnt[100010];

void insert(string str)
{
    int pos = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if(a[pos][str[i] - 'a'] == 0)
        {
            a[pos][str[i] - 'a'] = idx;
            pos = idx;
            idx++;
        }
        else
        {
            pos = a[pos][str[i] - 'a'];
        }
    }
    cnt[pos]++;
}

int query(string str)
{
    int pos = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if(a[pos][str[i] - 'a'] == 0)
            return 0;
        else
            pos = a[pos][str[i] - 'a'];
    }
    return cnt[pos];
}

int main()
{
    cin >> n;
    while(n--)
    {
        string command;
        string str;
        cin >> command;
        cin >> str;
        if(command == "I")
            insert(str);
        else
            cout << query(str) << endl;
    }

    return 0;
}