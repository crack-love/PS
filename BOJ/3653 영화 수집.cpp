// https://www.acmicpc.net/problem/3653
// platinum4

#include <iostream>
#include <cstring>
using namespace std;

struct p3453
{
	static const int LEAF_SIZE = 1 << 18;
	int seg[LEAF_SIZE * 2];

	void update(int si, int di, int beg, int end, int v)
	{
		if (di < beg || end < di) return;
		seg[si] += v;
		if (beg == end) return;
		int m = (beg + end) / 2;
		update(si * 2, di, beg, m, v);
		update(si * 2 + 1, di, m + 1, end, v);
	}

	int getsum(int si, int dbeg, int dend, int sbeg, int send)
	{
		if (dbeg > send || dend < sbeg) return 0;
		if (dbeg <= sbeg && send <= dend) return seg[si];
		int m = (sbeg + send) / 2;
		int s0 = getsum(si * 2, dbeg, dend, sbeg, m);
		int s1 = getsum(si * 2 + 1, dbeg, dend, m + 1, send);
		return s0 + s1;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int pos[(int)1e5 + 1];

			int n, m; // [1 1e5]
			int nextPos = 1;
			cin >> n >> m;
			for (int i = n; i >= 1; --i)
			{
				pos[i] = nextPos++;
				update(1, pos[i], 1, LEAF_SIZE, 1);
			}

			for (int i = 0; i < m; ++i)
			{
				int x;
				cin >> x;

				update(1, pos[x], 1, LEAF_SIZE, -1);
				int s = getsum(1, pos[x] + 1, nextPos - 1, 1, LEAF_SIZE);
				update(1, pos[x] = nextPos++, 1, LEAF_SIZE, 1);

				cout << s << ' ';
			}
			cout << '\n';

			memset(seg, 0, sizeof(int) * (nextPos + LEAF_SIZE));
		}

		return 0;
	}
};