// https://www.acmicpc.net/problem/14891

#include <bits/stdc++.h>
#include <cassert>
using namespace std;

struct p14891
{
	int a[4];

	void rotate(int i, int d, int pi)
	{
		assert(0 <= i && i <= 3);
		bool src, dst;
		if (i > 0 && i - 1 != pi)
		{
			dst = a[i - 1] & (1 << 2);
			src = a[i] & (1 << 6);
			if (src != dst) rotate(i - 1, -d, i);
		}
		if (i < 3 && i + 1 != pi)
		{
			dst = a[i + 1] & (1 << 6);
			src = a[i] & (1 << 2);
			if (src != dst) rotate(i + 1, -d, i);
		}

		bool t;
		if (d > 0)
		{
			t = a[i] & (1 << 7);
			a[i] <<= 1;
			a[i] |= t;
		}
		else if (d < 0)
		{
			t = a[i] & 1;
			a[i] >>= 1;
			a[i] |= t << 7;
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		string in;
		for (int i = 0; i < 4; ++i)
		{
			cin >> in;
			for (int j = 0; j < 8; ++j)
			{
				if (in[j] == '1')
				{
					a[i] |= 1 << j;
				}
			}
		}

		int k;
		cin >> k;
		for (int i = 0; i < k; ++i)
		{
			int a, b;
			cin >> a >> b;
			rotate(a - 1, b, -1);
		}

		int ans = 0;
		int v = 1;
		for (int i = 0; i < 4; ++i)
		{
			if (a[i] & 1) ans += v;
			v <<= 1;
		}
		cout << ans;
		return 0;
	}
};