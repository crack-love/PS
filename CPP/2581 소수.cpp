// https://www.acmicpc.net/problem/2581

#include <iostream>
using namespace std;

struct p2581
{
	int main()
	{
		int m, n;
		cin >> m >> n;

		int sum = 0;
		int min = 0;
		for (int i = m; i <= n; ++i)
		{
			if (i == 2)
			{
				sum += 2;
				min = 2;
				continue;
			}

			for (int j = 2; j < i; ++j)
			{
				if (i % j == 0)
				{
					break;
				}

				if (j == i - 1)
				{
					if (sum == 0)
					{
						min = i;
					}

					sum += i;
				}
			}
		}

		if (sum == 0)
		{
			cout << "-1\n";
		}
		else
		{
			cout << sum << "\n" << min << "\n";
		}
		return 0;
	}
};