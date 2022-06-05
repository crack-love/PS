// https://www.acmicpc.net/problem/1300
// gold2

#include <iostream>
using namespace std;

struct p1300
{
#define min(a,b) (a<b?a:b)

	int main()
	{
		int n, k; // [<=1e5], k = n^2 or max1e9
		cin >> n >> k;

		int l = 1;
		int r = 1e9;

		while (l < r)
		{
			// count less same with mid

			int mid = (l + r) / 2;

			int cnt = 0;
			for (int i = 1; i <= n; ++i)
			{
				cnt += min(mid / i, n);
			}

			if (cnt < k)
			{
				l = mid + 1;
			}
			else if (cnt >= k)
			{
				r = mid;
			}
		}

		cout << l;
	}
};