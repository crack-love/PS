// https://www.acmicpc.net/problem/6549
// platinum5

#include <iostream>
#include <algorithm>
using namespace std;

struct p6549
{
	typedef long long ll;
	static const int N_SIZE = 1e5;
	static const int INF = 1e9 + 1;
	static const int TREE_HEIGHT = 17;
	static const int NODE_SIZE = 1 << TREE_HEIGHT;

	int arr[N_SIZE + 1] = { INF, };
	int seg[NODE_SIZE + 1];

	int init(int cidx, int sbeg, int send, int n)
	{
		if (sbeg > n) return 0;
		if (sbeg == send) return sbeg;

		int m = (sbeg + send) / 2;
		int l = init(cidx * 2, sbeg, m, n);
		int r = init(cidx * 2 + 1, m + 1, send, n);
		return seg[cidx] = arr[l] <= arr[r] ? l : r;
	}

	int getMinIdx(int cidx, int abeg, int aend, int sbeg, int send)
	{
		if (abeg > send || aend < sbeg) return 0;
		if (sbeg == send) return sbeg;
		if (abeg <= sbeg && send <= aend) return seg[cidx];

		int m = (sbeg + send) / 2;
		int l = getMinIdx(cidx * 2, abeg, aend, sbeg, m);
		int r = getMinIdx(cidx * 2 + 1, abeg, aend, m + 1, send);
		return arr[l] <= arr[r] ? l : r;
	}

	ll getArea(int beg, int end)
	{
		if (beg > end) return 0;
		if (beg == end) return arr[beg];

		int m = getMinIdx(1, beg, end, 1, NODE_SIZE);
		ll area0 = arr[m] * ((ll)end - beg + 1);
		ll area1 = getArea(beg, m - 1);
		ll area2 = getArea(m + 1, end);
		return max(area0, max(area1, area2));
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		while (true)
		{
			int n;
			cin >> n;
			if (n == 0)
			{
				break;
			}

			for (int i = 1; i <= n; ++i)
			{
				cin >> arr[i];
			}

			init(1, 1, NODE_SIZE, n);

			cout << getArea(1, n) << "\n";
		}

		return 0;
	}
};