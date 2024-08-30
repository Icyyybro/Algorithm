#include<iostream>
#include<cstring>
#include<algorithm>
#define MIN_NUM -0x3f3f3f3f
using namespace std;


int a[510][510];
int f[510][510];
int n;


int main()
{
	cin >> n;
	memset(f, -0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	f[1][1] = a[1][1];

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
		{
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
		}

	int res = MIN_NUM;
	for (int i = 1; i <= n; i++)
		res = max(res, f[n][i]);

	cout << res << endl;
}