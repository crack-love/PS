// https://www.acmicpc.net/problem/2517
// platinum4

#include <iostream>
#include <algorithm>
using namespace std;

struct p2517
{
	static const int SIZE_N = (const int)5e5;
	static const int SIZE_NODE = 1 << 20;
	static const int SIZE_LEAF = 1 << 19;
	int seg[SIZE_NODE];

	void insert(int sidx, int didx, int sbeg, int send)
	{
		if (didx < sbeg || send < didx) return;
		seg[sidx] += 1;
		if (sbeg == send) return;
		int m = (sbeg + send) / 2;
		insert(sidx * 2, didx, sbeg, m);
		insert(sidx * 2 + 1, didx, m + 1, send);
	}

	int getCount(int sidx, int dbeg, int dend, int sbeg, int send)
	{
		if (dbeg > send || dend < sbeg) return 0;
		if (dbeg <= sbeg && send <= dend) return seg[sidx];
		int m = (sbeg + send) / 2;
		int c0 = getCount(sidx * 2, dbeg, dend, sbeg, m);
		int c1 = getCount(sidx * 2 + 1, dbeg, dend, m + 1, send);
		return c0 + c1;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		pair<int, int> a[SIZE_N];
		int itoa[SIZE_N];

		int n; // [3 5e5]
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i].first;
			a[i].second = i;
		}

		stable_sort(a, a + n);

		for (int i = 0; i < n; ++i)
		{
			itoa[a[i].second] = i;
		}

		for (int i = 0; i < n; ++i)
		{
			int idx = itoa[i];
			insert(1, idx, 0, SIZE_LEAF - 1);
			int c = getCount(1, idx + 1, SIZE_LEAF - 1, 0, SIZE_LEAF - 1);
			cout << c + 1 << "\n";
		}

		return 0;
	}
};