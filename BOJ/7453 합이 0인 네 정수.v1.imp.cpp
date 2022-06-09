// https://www.acmicpc.net/problem/7453
// gold2

#include <iostream>
#include <algorithm>
using namespace std;

struct p7453_imp
{
	int lowerBound(int l, int r, int v, int a[])
	{
		while (l < r)
		{
			int m = (l + r) / 2;

			if (a[m] < v)
			{
				l = m + 1;
			}
			else
			{
				r = m;
			}
		}

		return l;
	}

	int upperBound(int l, int r, int v, int a[])
	{
		while (l < r)
		{
			int m = (l + r) / 2;

			if (v < a[m])
			{
				r = m;
			}
			else
			{
				l = m + 1;
			}
		}

		return l;
	}

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

				int lb = lowerBound(0, n2, pred, s);
				int ub = upperBound(0, n2, pred, s);
				answer += ub - lb;
			}
		}

		cout << answer;
		return 0;
	}
};