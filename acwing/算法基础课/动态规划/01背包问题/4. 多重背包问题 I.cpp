#include <bits/stdc++.h>
using namespace std;

int N, V;
vector<int> v;
vector<int> w;
int f[2010];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        int volum, weight, num;
        cin >> volum >> weight >> num;
        int k = 0;
        int last = num;
        while (1)
        {
            int piece = pow(2, k);
            v.push_back(piece * volum);
            w.push_back(piece * weight);
            last -= piece;
            if (last < pow(2, k + 1))
            {
                if (last)
                {
                    v.push_back(last * volum);
                    w.push_back(last * weight);
                }
                break;
            }
            k++;
        }
    }

    for (int i = 0; i < v.size(); i++)
        for (int j = V; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }

    cout << f[V] << endl;
    return 0;
}