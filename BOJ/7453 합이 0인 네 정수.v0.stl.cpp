// https://www.acmicpc.net/problem/7453
// gold2

#include <iostream>
#include <algorithm>
using namespace std;

struct p7453_stl
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int a[4][4000];
		int s[16000000];
		int n; // [1 4k]
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cin >> a[j][i];
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				s[i * n + j] = a[2][i] + a[3][j];
			}
		}

		const int n2 = n * n;
		sort(s, s + n2);

		long long answer = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j) // n^2 * 2log2(n^2)
			{
				int pred = -(a[0][i] + a[1][j]);

				auto lb = lower_bound(s, s + n2, pred);
				auto ub = upper_bound(s, s + n2, pred);
				answer += ub - lb;
			}
		}

		cout << answer;
		return 0;
	}
};