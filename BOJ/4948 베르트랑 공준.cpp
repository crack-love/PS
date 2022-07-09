// https://www.acmicpc.net/problem/4948

#include <iostream>
using namespace std;

struct p4948
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		const int MAX = 250000;
		bool notPrime[MAX] = {};

		for (int i = 2; i < MAX; ++i)
		{
			if (notPrime[i]) continue;

			for (int j = i * 2; j < MAX; j += i)
			{
				notPrime[j] = true;
			}
		}

		while (true)
		{
			int n;
			cin >> n;
			if (n == 0)
			{
				break;
			}

			int answer = 0;
			for (int i = n + 1; i <= n * 2; ++i)
			{
				if (!notPrime[i])
				{
					answer += 1;
				}
			}

			cout << answer << "\n";
		}

		return 0;
	}
};