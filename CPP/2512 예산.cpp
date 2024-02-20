// https://www.acmicpc.net/problem/2512
// silver3

#include <iostream>
using namespace std;

struct p2512
{
#define max(a,b) (a<b?b:a)

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int n, m;
		int b[10000];
		int bsum = 0;
		int maxVal = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> b[i];
			bsum += b[i];
			maxVal = max(maxVal, b[i]);
		}
		cin >> m;

		if (bsum <= m)
		{
			cout << maxVal;
			return 0;
		}

		int l = 1;
		int r = maxVal + 1;
		while (l < r - 1)
		{
			int mid = (l + r) / 2;

			int sum = 0;
			for (int i = 0; i < n; ++i)
			{
				sum += b[i] < mid ? b[i] : mid;
			}

			if (sum > m)
			{
				r = mid;
			}
			else if (sum <= m)
			{
				l = mid;
			}
		}
		cout << l;
		return 0;
	}
};