// https://www.acmicpc.net/problem/1725
// platinum5

#include <iostream>
#include <algorithm>
using namespace std;

struct p1725
{
	typedef long long ll;
	static const int NODE_SIZE = 1 << 17;
	int arr[(int)1e5 + 1] = { (int)1e9 + 1, };
	int seg[NODE_SIZE];

	int init(int cidx, int sbeg, int send, int n)
	{
		if (sbeg > n) return 0;
		if (sbeg == send) return sbeg;

		int m = (sbeg + send) / 2;
		int l = init(cidx * 2, sbeg, m, n);
		int r = init(cidx * 2 + 1, m + 1, send, n);
		return seg[cidx] = arr[l] <= arr[r] ? l : r;
	}

	int getMinHeightIdx(int cidx, int sbeg, int send, int abeg, int aend)
	{
		if (sbeg > aend || send < abeg) return 0;
		if (sbeg == send) return sbeg;
		if (abeg <= sbeg && send <= aend) return seg[cidx];

		int m = (sbeg + send) / 2;
		int l = getMinHeightIdx(cidx * 2, sbeg, m, abeg, aend);
		int r = getMinHeightIdx(cidx * 2 + 1, m + 1, send, abeg, aend);
		return arr[l] <= arr[r] ? l : r;
	}

	ll getMaxArea(int beg, int end)
	{
		if (beg > end) return 0;
		if (beg == end) return arr[beg];

		int m = getMinHeightIdx(1, 1, NODE_SIZE, beg, end);
		ll area0 = arr[m] * ((ll)end - beg + 1);
		ll area1 = getMaxArea(beg, m - 1);
		ll area2 = getMaxArea(m + 1, end);
		return max(area0, max(area1, area2));
	}

	int main()
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> arr[i];
		}

		init(1, 1, NODE_SIZE, n);

		cout << getMaxArea(1, n);
	}
};