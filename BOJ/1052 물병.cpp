// https://www.acmicpc.net/problem/1052

#include <bits/stdc++.h>
using namespace std;

struct p1052
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n, k;
		cin >> n >> k;

		deque<pair<int, int>> dq; // lvl, cnt
		int tn = n;
		n = 0;
		while (tn > 0)
		{
			int lv = log2(tn);
			int cnt = pow(2, lv);
			tn -= cnt;
			dq.push_front({ lv, 1 });
			n += 1;
		}

		long long cost = 0;
		while (n > k)
		{
			// merge
			while (dq.size() > 1 && dq[0].first == dq[1].first)
			{
				dq[1].second += dq[0].second;
				dq.pop_front();
			}

			auto [lvl, cnt] = dq[0];
			int half = cnt / 2;
			if (half == 0)
			{
				cost += pow(2, lvl);
				half = 1;
				n += 1;
			}

			dq[0].first += 1;
			dq[0].second = half;
			n -= half;
		}

		cout << cost;
		return 0;
	}
};