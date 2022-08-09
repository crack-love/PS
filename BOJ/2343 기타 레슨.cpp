// https://www.acmicpc.net/problem/2343
// silver1

#include <iostream>
using namespace std;

struct p2343
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int t[100000] = {};

		int n, m; // [1 100000]
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> t[i];
		}

		int l = 1;
		int r = (int)1e4 * n + 1;
		while (l < r)
		{
			int mid = (l + r) / 2;

			int cnt = 1;
			int sum = 0;
			for (int i = 0; i < n; ++i)
			{
				// next disk
				while (sum + t[i] > mid)
				{
					cnt += 1;
					sum = 0;
					if (cnt > m) break;
				}
				sum += t[i];
			}

			if (cnt > m) // move right
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}

		cout << l;
		return 0;
	}
};