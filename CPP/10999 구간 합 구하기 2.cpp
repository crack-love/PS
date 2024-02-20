// https://www.acmicpc.net/problem/10999
// platinum4

#include <iostream>
#include <algorithm>
using namespace std;

struct p10999
{
	typedef long long ll;
	static const int SIZE_NODE = 1 << 21;
	static const int SIZE_LEAF = 1 << 20;
	ll seg[SIZE_NODE];
	ll lazy[SIZE_NODE];

	void clearLazy(int sidx, int sbeg, int send, int n)
	{
		if (lazy[sidx] != 0)
		{
			const ll value = lazy[sidx];
			const int size = min(n, send) - sbeg + 1;
			seg[sidx] += size * value;
			lazy[sidx] = 0;

			if (sbeg != send)
			{
				int m = (sbeg + send) / 2;
				lazy[sidx * 2] += value;
				lazy[sidx * 2 + 1] += value;
			}
		}
	}

	ll update(int sidx, int dbeg, int dend, int sbeg, int send, ll v, int n)
	{
		if (send < dbeg || dend < sbeg)
		{
			return 0;
		}

		clearLazy(sidx, sbeg, send, n);

		// finish from current node
		if (dbeg <= sbeg && send <= dend)
		{
			lazy[sidx] = v;
			const int size = min(n, send) - sbeg + 1;
			return size * v;
		}

		// move next node
		int m = (sbeg + send) / 2;
		ll u0 = update(sidx * 2, dbeg, dend, sbeg, m, v, n);
		ll u1 = update(sidx * 2 + 1, dbeg, dend, m + 1, send, v, n);
		seg[sidx] += u0 + u1;
		return u0 + u1;
	}

	ll getSum(int sidx, int dbeg, int dend, int sbeg, int send, int n)
	{
		if (send < dbeg || dend < sbeg)
		{
			return 0;
		}

		clearLazy(sidx, sbeg, send, n);

		if (dbeg <= sbeg && send <= dend)
		{
			return seg[sidx];
		}

		// move next
		int m = (sbeg + send) / 2;
		ll s0 = getSum(sidx * 2, dbeg, dend, sbeg, m, n);
		ll s1 = getSum(sidx * 2 + 1, dbeg, dend, m + 1, send, n);
		return s0 + s1;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n, m, k; // n[1 1e6], m[1 1e4], k[1 1e4]
		cin >> n >> m >> k;
		for (int i = 1; i <= n; ++i)
		{
			ll x;
			cin >> x;
			update(1, i, i, 1, SIZE_LEAF, x, n);
		}
		for (int i = 0; i < m + k; ++i)
		{
			ll a, b, c, d;
			cin >> a;
			if (a == 1)
			{
				cin >> b >> c >> d;
				update(1, b, c, 1, SIZE_LEAF, d, n);
			}
			else if (a == 2)
			{
				cin >> b >> c;
				cout << getSum(1, b, c, 1, SIZE_LEAF, n) << "\n";
			}
		}

		return 0;
	}
};