// https://www.acmicpc.net/problem/1654
// silver3

#include <iostream>
using namespace std;

struct p1654
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int len[10000] = {};

		// k[1 10000], n[1 1000000] k<=n
		int n, k;
		cin >> k >> n;
		for (int i = 0; i < k; ++i)
		{
			cin >> len[i];
		}

		long long l = 0;
		long long r = 2147483648;
		while (l < r)
		{
			int mid = (l + r) / 2;

			int cnt = 0;
			for (int i = 0; i < k; ++i)
			{
				cnt += len[i] / mid;
			}

			if (cnt < n) // to left
			{
				r = mid;
			}
			else if (cnt >= n) // to right
			{
				l = mid;
				if (l + 1 == r) 
					break;
			}
		}

		cout << l;
		return 0;
	}
};