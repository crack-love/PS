// https://www.acmicpc.net/problem/1275

#include <bits/stdc++.h>
using namespace std;

struct p1275
{
	static const int LEAF_SIZE = 1 << 17;
	static const int NODE_SIZE = 1 << 18;
	long long seg[NODE_SIZE];

	void update(int i, int x)
	{
		int sidx = LEAF_SIZE + i;
		seg[sidx] = x;
		while (sidx > 1)
		{
			sidx /= 2;
			seg[sidx] = seg[sidx * 2] + seg[sidx * 2 + 1];
		}
	}

	long long get(int x, int y)
	{
		x += LEAF_SIZE;
		y += LEAF_SIZE;
		long long sum = 0;
		while (x < y)
		{
			if (x % 2 == 1)
			{
				sum += seg[x];
				x = x / 2 + 1;
			}
			else x /= 2;
			if (y % 2 == 0)
			{
				sum += seg[y];
				y = y / 2 - 1;
			}
			else y /= 2;
		}
		if (x == y)
			sum += seg[x];
		return sum;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			update(i, x);
		}

		while (q--)
		{
			int x, y, a, b;
			cin >> x >> y >> a >> b;
			if (x > y) swap(x, y);
			cout << get(x - 1, y - 1) << "\n";
			update(a - 1, b);
		}

		return 0;
	}
};