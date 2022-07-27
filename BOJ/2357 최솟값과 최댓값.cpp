// https://www.acmicpc.net/problem/2357

#include <iostream>
using namespace std;

struct p2357
{
	static const int LEAF_SIZE = 1 << 17;
	static const int NODE_SIZE = 1 << 18;
	int minseg[NODE_SIZE];
	int maxseg[NODE_SIZE];

	typedef const int& (*selecter)(const int& src, const int& dst);

	void insert(int sidx, int didx, int sbeg, int send, int v, int seg[], selecter select)
	{
		if (didx < sbeg || didx > send) return;
		if (sbeg == send)
		{
			seg[sidx] = v;
			return;
		}

		seg[sidx] = select(seg[sidx], v);

		int m = (sbeg + send) / 2;
		insert(sidx * 2, didx, sbeg, m, v, seg, select);
		insert(sidx * 2 + 1, didx, m + 1, send, v, seg, select);
	}

	int getvalue(int sidx, int dbeg, int dend, int sbeg, int send, int seg[], selecter select)
	{
		if (dend < sbeg || send < dbeg) return -1;
		if (dbeg <= sbeg && send <= dend) return seg[sidx];
		if (sbeg == send)
		{
			return seg[sidx];
		}

		int m = (sbeg + send) / 2;
		int v0 = getvalue(sidx * 2, dbeg, dend, sbeg, m, seg, select);
		int v1 = getvalue(sidx * 2 + 1, dbeg, dend, m + 1, send, seg, select);
		if (v0 == -1) return v1;
		else if (v1 == -1) return v0;
		else return select(v0, v1);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		fill(minseg, minseg + NODE_SIZE, 1e9 + 1);
		fill(maxseg, maxseg + NODE_SIZE, 0);

		int a[100000];
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			int x;
			cin >> x;
			insert(1, i, 1, LEAF_SIZE, x, minseg, min<int>);
			insert(1, i, 1, LEAF_SIZE, x, maxseg, max<int>);
		}

		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			cout << getvalue(1, a, b, 1, LEAF_SIZE, minseg, min<int>) << " ";
			cout << getvalue(1, a, b, 1, LEAF_SIZE, maxseg, max<int>) << "\n";
		}

		return 0;
	}
};