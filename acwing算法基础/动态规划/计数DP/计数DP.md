# 计数DP

# 1. 题目

![](image/image_NmXSiW2quy.png)

# 2. 思路

f\[i]\[j]表示在1\~i这i个数中，选择一些数，使这些数加起来恰好为j的方法数。类似于背包问题：把1,2,3, … n分别看做n个物体的体积，这n个物体均无使用次数限制，问恰好能装满总体积为n的背包的总方案数。

f\[i]\[j]可以有两种情况。第一种：不选i，那么方案数为f\[i - 1]\[j]；第二种：选择若干个i，那么方案数为f\[i - 1]\[j - k \* i]。所以综上所述:

f\[i]\[j] = f\[i - 1]\[j] + f\[i - 1]\[j - i] + f\[i - 1]\[j - 2 \* i] + ...;

又因为：
f\[i]\[j - i] = f\[i - 1]\[j - i] + f\[i - 1]\[j - 2 \* i] + ...;

所以：

f\[i]\[j] = f\[i - 1]\[j] + f\[i]\[j - i]

# 3. 代码

```c++
#include <iostream>
using namespace std;

int n;
int f[1010][1010];
int mod = 1e9 + 7;

int main()
{
    cin >> n;
    // 因为什么都不选也是一种方案
    for (int i = 1; i <= n; i++)
        f[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] % mod;
            if (j >= i)
                f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod;
        }

    cout << f[n][n] << endl;
    return 0;
}
```

f\[i]\[j] = f\[i - 1]\[j] + f\[i - 1]\[j - i] + f\[i - 1]\[j - 2 \* i] + ...;
f\[i]\[j - i] = f\[i - 1]\[j - i] + f\[i - 1]\[j - 2 \* i] + ...;

# 4. 优化

```c++
#include <iostream>
using namespace std;

int n;
int f[1010];
int mod = 1e9 + 7;

int main()
{
    cin >> n;
    f[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
                f[j] = (f[j] + f[j - i]) % mod;
        }

    cout << f[n] << endl;
    return 0;
}


```
