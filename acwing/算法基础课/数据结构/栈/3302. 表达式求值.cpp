#include <bits/stdc++.h>
using namespace std;

string str;
vector<int> num;
vector<char> symbol;
unordered_map<char, int> priority = {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};

int calculate()
{
    char c = symbol.back();
    symbol.pop_back();
    int n2 = num.back();
    num.pop_back();
    int n1 = num.back();
    num.pop_back();

    if (c == '+')
        num.push_back(n1 + n2);
    else if (c == '-')
        num.push_back(n1 - n2);
    else if (c == '*')
        num.push_back(n1 * n2);
    else
        num.push_back(n1 / n2);
}

int main()
{
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        // 处理数字
        if (str[i] >= '0' && str[i] <= '9')
        {
            int sum = 0;
            while (i < str.size() && str[i] >= '0' && str[i] <= '9')
            {
                sum = sum * 10 + str[i] - '0';
                i++;
            }
            i--;
            num.push_back(sum);
        }
        else
        {
            if (str[i] == '(')
                symbol.push_back(str[i]);
            else if (str[i] == ')')
            {
                while (symbol.back() != '(')
                    calculate();
                symbol.pop_back();
            }
            else
            {
                while(symbol.size() && priority[symbol.back()] >= priority[str[i]])
                    calculate();
                symbol.push_back(str[i]);
            }
        }
    }

    if (symbol.size())
        calculate();

    cout << num[0] << endl;
    return 0;
}