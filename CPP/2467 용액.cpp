// https://www.acmicpc.net/problem/2467
// gold5

#include <iostream>
#include <cmath>
using namespace std;

struct p2467
{
	typedef long long ll;

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int a[(int)1e5];
		int n; // [2 1e5]
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		int l = 0;
		int r = n - 1;
		ll minSum = (ll)2e9 + 1;
		int ansX;
		int ansY;

		while (l < r)
		{
			ll s0 = abs((ll)a[l] + a[r]);

			if (s0 < minSum)
			{
				ansX = l;
				ansY = r;
				minSum = s0;
			}

			ll s1 = abs((ll)a[l + 1] + a[r]);
			ll s2 = abs((ll)a[r - 1] + a[l]);
			if (s1 < s2)
			{
				l += 1;
			}
			else
			{
				r -= 1;
			}
		}

		cout << a[ansX] << " " << a[ansY];
		return 0;
	}
};