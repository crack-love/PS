// https://www.acmicpc.net/problem/2042
// gold1

#include <iostream>
#include <cmath>
using namespace std;

struct p2042
{
	typedef long long ll;
	static const int MAX_HEIGHT = 20;
	static const int MAX_NODE = (1 << (MAX_HEIGHT + 1));
	static const int MAX_LEAF = (1 << MAX_HEIGHT);

	ll seg[MAX_NODE];

	ll get(int idx)
	{
		return seg[MAX_LEAF + idx - 1];
	}

	ll getSum_internal(int cidx, int dbeg, int dend, int beg, int end)
	{
		if (dbeg <= beg && end <= dend)
		{
			return seg[cidx];
		}

		ll sum = 0;
		int m = (beg + end) / 2;
		if (dbeg <= m)
		{
			sum += getSum_internal(cidx * 2, dbeg, dend, beg, m);
		}
		if (dend >= m + 1)
		{
			sum += getSum_internal(cidx * 2 + 1, dbeg, dend, m + 1, end);
		}
		return sum;
	}

	ll getSum(int beg, int end)
	{
		return getSum_internal(1, beg, end, 1, MAX_LEAF);
	}

	void update_internal(int cidx, int didx, int beg, int end, ll v)
	{
		seg[cidx] += v;

		if (beg == end)
		{
			return;
		}

		int m = (beg + end) / 2;
		if (beg <= didx && didx <= m)
		{
			update_internal(cidx * 2, didx, beg, m, v);
		}
		else
		{
			update_internal(cidx * 2 + 1, didx, m + 1, end, v);
		}
	}

	void update(int idx, ll v)
	{
		update_internal(1, idx, 1, MAX_LEAF, v);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		// n[1 1e6] m[1 1e4] k[1 1e4]
		int n, m, k;
		cin >> n >> m >> k;

		for (int i = 1; i <= n; ++i)
		{
			ll x;
			cin >> x;
			update(i, x);
		}

		for (int i = 0; i < m + k; ++i)
		{
			ll a, b, c;
			cin >> a >> b >> c;

			if (a == 1)
			{
				update(b, c - get(b));
			}
			else if (a == 2)
			{
				cout << getSum(b, c) << "\n";
			}
		}

		return 0;
	}
};