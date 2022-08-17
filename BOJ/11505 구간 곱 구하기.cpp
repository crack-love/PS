// https://www.acmicpc.net/problem/11505

#include <bits/stdc++.h>
using namespace std;

struct p11505
{
	inline static const int getLeafSize(const int maxn)
	{
		return 1 << (int)ceil(log2(maxn));
	}
	inline static const int MOD = (int)1e9 + 7;
	inline static const int LEAF_SIZE = getLeafSize((int)1e6);

	vector<int> seg = vector<int>(LEAF_SIZE);

	int update(int sidx, int sbeg, int send, int didx, int v)
	{
		if (didx < sbeg || send < didx)
		{
			return seg[sidx];
		}
		if (sbeg == send)
		{
			return seg[sidx] = v;
		}

		int m = (sbeg + send) / 2;
		int u0 = update(sidx * 2, sbeg, m, didx, v);
		int u1 = update(sidx * 2 + 1, m + 1, send, didx, v);
		return seg[sidx] = ((long long)u0 * u1) % MOD;
	}

	int get(int sidx, int sbeg, int send, int dbeg, int dend)
	{
		if (dbeg > send || dend < sbeg) return 1;
		if (dbeg <= sbeg && send <= dend) return seg[sidx];

		int m = (sbeg + send) / 2;
		int g0 = get(sidx * 2, sbeg, m, dbeg, dend);
		int g1 = get(sidx * 2 + 1, m + 1, send, dbeg, dend);
		return ((long long)g0 * g1) % MOD;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			update(1, 1, LEAF_SIZE, i + 1, x);
		}

		for (int i = 0; i < m + k; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (a == 1)
			{
				update(1, 1, LEAF_SIZE, b, c);
			}
			else if (a == 2)
			{
				cout << get(1, 1, LEAF_SIZE, b, c) << "\n";
			}
		}

		return 0;
	}
};

int main()
{
	p11505().main();
}