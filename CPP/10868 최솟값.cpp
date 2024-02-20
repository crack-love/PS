// https://www.acmicpc.net/problem/10868

#include <bits/stdc++.h>
using namespace std;

struct p10868
{
	static const int LEAF_SIZE = 1 << 17;
	static const int NODE_SIZE = 1 << 18;
	static const int INF = (int)1e9 + 1;
	int seg[NODE_SIZE];

	void insert(int sidx, int didx, int sbeg, int send, int v)
	{
		if (didx < sbeg || send < didx) return;
		if (sbeg == send)
		{
			seg[sidx] = v;
			return;
		}

		seg[sidx] = min(seg[sidx] == 0 ? INF : seg[sidx], v);
		int m = (send + sbeg) / 2;
		insert(sidx * 2, didx, sbeg, m, v);
		insert(sidx * 2 + 1, didx, m + 1, send, v);
	}

	int getMin(int sidx, int dbeg, int dend, int sbeg, int send)
	{
		if (send < dbeg || dend < sbeg) return INF;
		if (dbeg <= sbeg && send <= dend) return seg[sidx];

		int m = (sbeg + send) / 2;
		int v0 = getMin(sidx * 2, dbeg, dend, sbeg, m);
		int v1 = getMin(sidx * 2 + 1, dbeg, dend, m + 1, send);
		return min(v0, v1);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			int x;
			cin >> x;
			insert(1, i, 1, LEAF_SIZE, x);
		}

		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			cout << getMin(1, a, b, 1, LEAF_SIZE) << "\n";
		}

		return 0;
	}
};