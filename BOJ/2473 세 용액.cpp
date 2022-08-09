// https://www.acmicpc.net/problem/2473
// gold3

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct p2473
{
	typedef long long ll;

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		ll INF = (ll)3e9 + 1;
		ll a[5000];
		int n; // [3 5000]

		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		sort(a, a + n);

		ll minSum = INF;
		int ansX;
		int ansY;
		int ansZ;

		for (int i = 1; i < n - 1; ++i)
		{
			int l = 0;
			int r = n - 1;

			while (l < r && l < i && i < r)
			{
				ll s0 = abs(a[l] + a[r] + a[i]);

				if (s0 < minSum)
				{
					ansX = a[l];
					ansY = a[i];
					ansZ = a[r];
					minSum = s0;
				}

				ll s1 = abs(a[l + 1] + a[r] + a[i]);
				ll s2 = abs(a[r - 1] + a[l] + a[i]);
				if (s1 < s2)
				{
					l += 1;
				}
				else
				{
					r -= 1;
				}
			}
		}

		cout << ansX << " " << ansY << " " << ansZ;

		return 0;
	}
};