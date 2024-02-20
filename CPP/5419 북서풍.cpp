// https://www.acmicpc.net/problem/5419

#include <iostream>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;

struct p5419
{
	using ti3 = tuple<int, int, int>;

	static const int LEAF_SIZE = 1 << 17;
	static const int NODE_SIZE = 1 << 18;
	ti3 arr[(int)7.5e4];
	int seg[NODE_SIZE];

	void insert(int sidx, int didx, int sbeg, int send)
	{
		if (didx < sbeg || send < didx) return;
		seg[sidx] += 1;
		if (sbeg == send) return;
		int m = (sbeg + send) / 2;
		insert(sidx * 2, didx, sbeg, m);
		insert(sidx * 2 + 1, didx, m + 1, send);
	}

	int count(int sidx, int dbeg, int dend, int sbeg, int send)
	{
		if (dend < sbeg || send < dbeg) return 0;
		if (dbeg <= sbeg && send <= dend) return seg[sidx];
		int m = (sbeg + send) / 2;
		int c0 = count(sidx * 2, dbeg, dend, sbeg, m);
		int c1 = count(sidx * 2 + 1, dbeg, dend, m + 1, send);
		return c0 + c1;
	}

	int main()
	{
		// sort as x(less) y(greater)
		// input beg x
		// count less x bigger y

		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			for (int i = 0; i < n; ++i)
			{
				int x, y;
				cin >> x >> y;
				arr[i] = { x, y, 0 };
			}

			sort(arr, arr + n, [](const ti3& a, const ti3& b)
				{
					int x0 = get<0>(a);
					int x1 = get<0>(b);
					int y0 = get<1>(a);
					int y1 = get<1>(b);
					if (y0 == y1) return x0 < x1;
					return y0 > y1;
				});

			for (int i = 0; i < n; ++i)
			{
				get<2>(arr[i]) = i;
			}

			sort(arr, arr + n, [](const ti3& a, const ti3& b)
				{
					int x0 = get<0>(a);
					int x1 = get<0>(b);
					int y0 = get<1>(a);
					int y1 = get<1>(b);
					if (x0 == x1) return y0 > y1;
					return x0 < x1;
				});

			memset(seg, 0, sizeof seg);

			long long answer = 0;
			for (int i = 0; i < n; ++i)
			{
				int yi = get<2>(arr[i]);
				insert(1, yi, 0, LEAF_SIZE - 1);
				answer += count(1, 0, yi - 1, 0, LEAF_SIZE - 1);
			}
			cout << answer << "\n";
		}

		return 0;
	}
};