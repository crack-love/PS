// https://www.acmicpc.net/problem/2243

#include <iostream>
using namespace std;

struct p2243
{
	static const int MAX_HEGIHT = 20;
	static const int LEAF_SIZE = 1 << MAX_HEGIHT;
	static const int LEAF_START = 1 << MAX_HEGIHT;
	int seg[1 << (MAX_HEGIHT + 1)] = {};

	void update(int idx, int beg, int end, int a, int b)
	{
		seg[idx] += b;

		if (beg == end)
		{
			return;
		}

		int m = (beg + end) / 2;
		if (beg <= a && a <= m)
		{
			update(idx * 2, beg, m, a, b);
		}
		if (m + 1 <= a && a <= end)
		{
			update(idx * 2 + 1, m + 1, end, a, b);
		}
	}

	int pop(int idx, int v)
	{
		seg[idx] -= 1;

		if (idx >= LEAF_START)
		{
			return idx;
		}

		int ls = seg[idx * 2];
		int rs = seg[idx * 2 + 1];

		if (v <= ls)
		{
			return pop(idx * 2, v);
		}
		else
		{
			return pop(idx * 2 + 1, v - ls);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n; // [1 1e5]
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int o;
			cin >> o;

			if (o == 1)
			{
				int x;
				cin >> x;
				int idx = pop(1, x);
				cout << idx - LEAF_START + 1 << "\n";
			}
			else if (o == 2)
			{
				int a, b;
				cin >> a >> b;
				update(1, 1, LEAF_SIZE, a, b);
			}
		}

		return 0;
	}
};