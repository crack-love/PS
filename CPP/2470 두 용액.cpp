// https://www.acmicpc.net/problem/2470
// gold5

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct p2470
{
	typedef long long ll;

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		ll arr[100000];
		int n; // [2 100000]
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);

		int l = 0;
		int r = n - 1;

		int ansX = l;
		int ansY = r;
		ll ansS = abs(arr[l] + arr[r]);

		while (l < r)
		{
			ll sum = abs(arr[l] + arr[r]);
			if (sum < ansS)
			{
				ansS = sum;
				ansX = l;
				ansY = r;
			}

			if (abs(arr[l]) > abs(arr[r]))
			{
				l += 1;
			}
			else
			{
				r -= 1;
			}
		}

		cout << arr[ansX] << " " << arr[ansY];
		return 0;
	}
};
