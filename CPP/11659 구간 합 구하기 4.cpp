// https://www.acmicpc.net/problem/11659
// silver3

#include <iostream>
using namespace std;

struct p11659
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int a[(int)1e5 + 1] = {};

		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			int x;
			cin >> x;
			a[i] = a[i - 1] + x;
		}

		long long sum = 0;
		for (int i = 0; i < m; ++i)
		{
			int x, y;
			cin >> x >> y;
			cout << a[y] - a[x - 1] << '\n';
		}

		return 0;
	}
};