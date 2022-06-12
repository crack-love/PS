// https://www.acmicpc.net/problem/1517
// platinum5

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

struct p1517
{
	static const int NODE_SIZE = 1 << 20;
	static const int LEAF_SIZE = 1 << 19;

	pair<int, int> arr[(int)5e5];
	int seg[NODE_SIZE];

	long long getSum(int cidx, int abeg, int aend, int sbeg, int send)
	{
		if (abeg > aend) return 0;
		if (aend < sbeg || send < abeg) return 0;
		if (abeg <= sbeg && send <= aend) return seg[cidx];

		int m = (sbeg + send) / 2;
		long long s0 = getSum(cidx * 2, abeg, aend, sbeg, m);
		long long s1 = getSum(cidx * 2 + 1, abeg, aend, m + 1, send);
		return s0 + s1;
	}

	void insert(int cidx, int didx, int beg, int end)
	{
		if (didx < beg || end < didx) return;

		seg[cidx] += 1;

		if (beg != end)
		{
			int m = (beg + end) / 2;
			insert(cidx * 2, didx, beg, m);
			insert(cidx * 2 + 1, didx, m + 1, end);
		}
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
			cin >> arr[i].first;
			arr[i].second = i;
		}

		sort(arr, arr + n);

		long long answer = 0;
		for (int i = 0; i < n; ++i)
		{
			insert(1, arr[i].second, 0, LEAF_SIZE - 1);
			answer += getSum(1, arr[i].second + 1, n - 1, 0, LEAF_SIZE - 1);
		}

		cout << answer;
		return 0;
	}
};