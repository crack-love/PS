// https://www.acmicpc.net/problem/7578
// platinum5

#include <iostream>
using namespace std;

struct p7578
{
	static const int SIZE_NODE = 1 << 21;
	static const int SIZE_LEAF = 1 << 20;
	int seg[SIZE_NODE];
	int pos[(int)1e6 + 1];

	void insert(int sidx, int didx, int sbeg, int send)
	{
		if (didx < sbeg || send < didx) return;
		seg[sidx] += 1;
		if (sbeg == send) return;
		int m = (sbeg + send) / 2;
		insert(sidx * 2, didx, sbeg, m);
		insert(sidx * 2 + 1, didx, m + 1, send);
	}

	int getSum(int sidx, int dbeg, int dend, int sbeg, int send)
	{
		if (dbeg > send || dend < sbeg) return 0;
		if (dbeg <= sbeg && send <= dend) return seg[sidx];
		int m = (sbeg + send) / 2;
		int s0 = getSum(sidx * 2, dbeg, dend, sbeg, m);
		int s1 = getSum(sidx * 2 + 1, dbeg, dend, m + 1, send);
		return s0 + s1;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			pos[x] = i;
		}

		long long answer = 0;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			insert(1, pos[x], 0, SIZE_LEAF - 1);
			answer += getSum(1, pos[x] + 1, SIZE_LEAF - 1, 0, SIZE_LEAF - 1);
		}

		cout << answer;
	}
};