// https://www.acmicpc.net/problem/6988
// gold1

#include <iostream>
using namespace std;

struct p6988_for
{
	typedef long long ll;

	int n; // [3 3000]
	int arr[3001]; // [1 1000000]
	int idx[1000001];

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> arr[i];
			idx[arr[i]] = i;
		}

		ll answer = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				ll sum = arr[i];
				int diff = arr[j] - arr[i];
				int cnt = 1;
				int k = j;

				while (k > 0)
				{
					sum += arr[k];
					cnt += 1;

					if (arr[k] + diff > 1000'000) break;
					k = idx[arr[k] + diff];
				}

				if (cnt >= 3 && sum > answer)
				{
					answer = sum;
				}
			}
		}
		cout << answer;
		return 0;
	}
};