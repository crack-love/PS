// https://www.acmicpc.net/problem/6988
// gold1

#include <iostream>
using namespace std;

struct p6988
{
	typedef long long ll;

	int n; // [3 3000]
	int arr[3001]; // [1 1000000]
	int idx[1000001];
	ll d[3001][3001];

	// i에서 j칸으로 점프한 합, 이후 누적
	ll dp(int i, int j)
	{
		if (d[i][j] != 0)
		{
			return d[i][j];
		}

		int diff = arr[j] - arr[i];
		int kval = arr[j] + diff;
		if (kval >= 1000001) return arr[j];

		int k = idx[kval];
		if (k == 0) return arr[j];

		return d[i][j] = dp(j, k) + arr[j];
	}

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
				ll r = dp(i, j) + arr[i];
				int diff = arr[j] - arr[i];
				ll cap = 3 * (arr[i] + (ll)diff);

				if (r >= cap && r > answer)
				{
					answer = r;
				}
			}
		}
		cout << answer;
		return 0;
	}
};