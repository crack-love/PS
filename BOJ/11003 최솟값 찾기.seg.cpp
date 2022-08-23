// https://www.acmicpc.net/problem/11003

#include <bits/stdc++.h>
using namespace std;

struct p11003_seg
{
	int n, l;
	static const int LEAF_SIZE = 1 << 23;
	static const int NODE_SIZE = LEAF_SIZE * 2;
	static const int INF = (int)1e9 + 1;
	int seg[NODE_SIZE];

	void build()
	{
		seg[LEAF_SIZE + n] = INF;
		for (int i = 0; i < n; i += 2)
		{
			int j = LEAF_SIZE + i;
			while (j > 0)
			{
				j >>= 1;
				seg[j] = min(seg[j * 2], seg[j * 2 + 1]);
			}
		}
	}


	int getmin(int l, int r)
	{
		l += LEAF_SIZE;
		r += LEAF_SIZE;
		int ans = INF;
		while (l <= r)
		{
			ans = min({ ans, seg[l], seg[r] });
			l = (l >> 1) + ((l % 2 == 1) ? 1 : 0);
			r = (r >> 1) + ((r % 2 == 0) ? -1 : 0);
		}
		return ans;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		cin >> n >> l;
		for (int i = 0; i < n; ++i)
		{
			cin >> seg[LEAF_SIZE + i];
		}
		build();

		for (int i = 0; i < n; ++i)
		{
			int beg = max(i - l + 1, 0);
			cout << getmin(beg, i) << " ";
		}

		return 0;
	}
};