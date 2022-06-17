// https://www.acmicpc.net/problem/16975
// platinum4

#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

struct p16975
{
	static const int SIZE_NODE = 1 << 18;
	static const int SIZE_LEAF = 1 << 17;

	ll seg[SIZE_NODE];
	ll lazy[SIZE_NODE];

	void clearLazy(int sidx, int sbeg, int send, int n)
	{
		if (lazy[sidx] != 0)
		{
			seg[sidx] += lazy[sidx] * (min(send, n) - sbeg + 1);
			if (sidx * 2 + 1 < SIZE_NODE)
			{
				lazy[sidx * 2] += lazy[sidx];
				lazy[sidx * 2 + 1] += lazy[sidx];
			}
			lazy[sidx] = 0;
		}
	}

	ll update(int sidx, int dbeg, int dend, int sbeg, int send, int v, int n)
	{
		if (dend < sbeg || send < dbeg) return 0;

		clearLazy(sidx, sbeg, send, n);

		if (dbeg <= sbeg && send <= dend)
		{
			lazy[sidx] += v;
			return (ll)v * (min(send, n) - sbeg + 1);
		}

		int m = (sbeg + send) / 2;
		ll u0 = update(sidx * 2, dbeg, dend, sbeg, m, v, n);
		ll u1 = update(sidx * 2 + 1, dbeg, dend, m + 1, send, v, n);
		seg[sidx] += u0 + u1;
		return u0 + u1;
	}

	ll get(int sidx, int didx, int sbeg, int send, int n)
	{
		if (didx < sbeg || didx > send) return 0;

		clearLazy(sidx, sbeg, send, n);

		if (sbeg == send)
		{
			return seg[sidx];
		}

		int m = (sbeg + send) / 2;
		ll g0 = get(sidx * 2, didx, sbeg, m, n);
		ll g1 = get(sidx * 2 + 1, didx, m + 1, send, n);
		return g0 + g1;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n, m;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			int x;
			cin >> x;
			update(1, i, i, 1, SIZE_LEAF, x, n);
		}
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			int o, x, y, k;
			cin >> o;
			if (o == 1)
			{
				cin >> x >> y >> k;
				update(1, x, y, 1, SIZE_LEAF, k, n);
			}
			else if (o == 2)
			{
				cin >> x;
				cout << get(1, x, 1, SIZE_LEAF, n) << '\n';
			}
		}

		return 0;
	}
};