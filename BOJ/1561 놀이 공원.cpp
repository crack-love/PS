// https://www.acmicpc.net/problem/1561
// gold2

#include <iostream>
using namespace std;

struct p1561
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int dur[10000] = {};

		int n, m; // n[1 2000000000] m[1 10000]
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> dur[i]; // [1 30]
		}

		long long l = 0;
		long long r = n / m * 30ll;
		while (l < r)
		{
			long long mid = (l + r) / 2;
			long long sum = 0;
			for (int i = 0; i < m; ++i)
			{
				sum += mid / dur[i] + 1;
			}

			if (sum < n) // to right
			{
				l = mid + 1;
			}
			else if (sum >= n) // to left
			{
				r = mid;
			}
		}

		int befSum = 0;
		if (l != 0)
		{
			for (int i = 0; i < m; ++i)
			{
				befSum += (l - 1) / dur[i] + 1;
			}
		}

		for (int i = 0; i < m; ++i)
		{
			if (l % dur[i] == 0)
			{
				befSum += 1;
				if (befSum >= n)
				{
					cout << i + 1;
					break;
				}
			}
		}

		return 0;
	}
};