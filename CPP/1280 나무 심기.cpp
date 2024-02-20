// https://www.acmicpc.net/problem/1280
// platinum4

#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

struct p1280
{
	using ll = long long;
	static const int N_SIZE = (int)2e5;
	static const int LEAF_SIZE = 1 << 18;
	static const int NODE_SIZE = 1 << 19;
	static const int MOD = 1000'000'007;
	pair<ll, int> seg[NODE_SIZE];

	void insert(int sidx, int didx, int sbeg, int send, int v)
	{
		if (didx < sbeg || send < didx) return;
		seg[sidx].first += v;
		seg[sidx].second += 1;
		if (sbeg == send) return;
		int m = (sbeg + send) / 2;
		insert(sidx * 2, didx, sbeg, m, v);
		insert(sidx * 2 + 1, didx, m + 1, send, v);
	}

	pair<ll, int> getSum(int sidx, int dbeg, int dend, int sbeg, int send)
	{
		if (dend < sbeg || send < dbeg) return {};
		if (dbeg <= sbeg && send <= dend) return seg[sidx];
		int m = (sbeg + send) / 2;
		auto s0 = getSum(sidx * 2, dbeg, dend, sbeg, m);
		auto s1 = getSum(sidx * 2 + 1, dbeg, dend, m + 1, send);
		return { s0.first + s1.first, s0.second + s1.second };
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		// 좌측에 있는 나무와의 거리 = n*d - sum
		// 우측에 있는 나무와의 거리 = sum - n*d

		struct input
		{
			int value;
			int inpIdx;
			int segIdx;
		};
		input arr[N_SIZE];

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i].value;
			arr[i].inpIdx = i;
		}

		sort(arr, arr + n, [](input& a, input& b)
			{
				return a.value < b.value;
			});

		for (int i = 0; i < n; ++i)
		{
			arr[i].segIdx = i;
		}

		sort(arr, arr + n, [](input& a, input& b)
			{
				return a.inpIdx < b.inpIdx;
			});

		insert(1, arr[0].segIdx, 0, LEAF_SIZE - 1, arr[0].value);

		ll answer = 1;
		for (int i = 1; i < n; ++i)
		{
			insert(1, arr[i].segIdx, 0, LEAF_SIZE - 1, arr[i].value);

			auto lsum = getSum(1, 0, arr[i].segIdx - 1, 0, LEAF_SIZE - 1);
			auto rsum = getSum(1, arr[i].segIdx + 1, n - 1, 0, LEAF_SIZE - 1);

			ll lcost = (ll)lsum.second * arr[i].value - lsum.first;
			ll rcost = rsum.first - (ll)rsum.second * arr[i].value;
			ll mcost = (lcost + rcost) % MOD;

			answer = (answer * mcost) % MOD;
		}

		cout << answer << "\n";
		return 0;
	}
};