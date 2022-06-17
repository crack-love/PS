// https://www.acmicpc.net/problem/2104
// platinum5

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

struct p2104
{
	using ll = long long;

	static const int SIZE_N = (int)1e5 + 1;
	static const int SIZE_NODE = 1 << 17;

	int arr[SIZE_N];
	ll segSum[SIZE_NODE];
	int segMin[SIZE_NODE];

	void insert(int sidx, int didx, int sbeg, int send, int v)
	{
		if (didx < sbeg || send < didx) return;
		if (sbeg == send) return;

		segSum[sidx] += v;
		if (arr[segMin[sidx]] > v)
		{
			segMin[sidx] = didx;
		}
		int m = (sbeg + send) / 2;
		insert(sidx * 2, didx, sbeg, m, v);
		insert(sidx * 2 + 1, didx, m + 1, send, v);
	}

	pair<ll, int> getSumMin(int sidx, int dbeg, int dend, int sbeg, int send)
	{
		if (dbeg > send || dend < sbeg) return {};
		if (sbeg == send) return { arr[sbeg], sbeg };
		if (dbeg <= sbeg && send <= dend) return { segSum[sidx], segMin[sidx] };

		int m = (sbeg + send) / 2;
		pair<ll, int> p0 = getSumMin(sidx * 2, dbeg, dend, sbeg, m);
		pair<ll, int> p1 = getSumMin(sidx * 2 + 1, dbeg, dend, m + 1, send);

		int minIdx = arr[p0.second] < arr[p1.second] ? p0.second : p1.second;
		return { p0.first + p1.first, minIdx };
	}

	ll dnq(int beg, int end)
	{
		if (beg > end) return 0;
		pair<ll, int> sm = getSumMin(1, beg, end, 1, SIZE_NODE);
		ll ans0 = sm.first * arr[sm.second];
		ll ans1 = dnq(beg, sm.second - 1);
		ll ans2 = dnq(sm.second + 1, end);
		return max(ans0, max(ans1, ans2));
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		arr[0] = (int)1e6 + 1;

		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> arr[i];
			insert(1, i, 1, SIZE_NODE, arr[i]);
		}

		cout << dnq(1, n) << "\n";
		return 0;
	}
};