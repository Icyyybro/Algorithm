#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> num;

int check(int x)
{
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (num[i] < x)
            return num[i];
    }
    return -1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cout << check(x) << " ";
        while (num.size() && num.back() >= x)
            num.pop_back();
        num.push_back(x);
    }
    return 0;
}