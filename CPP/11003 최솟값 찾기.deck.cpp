// https://www.acmicpc.net/problem/11003

#include <bits/stdc++.h>
using namespace std;

struct p11003_deck
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n, l;
		cin >> n >> l;
		deque<pair<int, int>> dq;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			if (dq.size() == 0)
			{
				dq.push_back({ x, i });
			}
			else
			{
				while (!dq.empty() && dq.front().second < i - l + 1)
				{
					dq.pop_front();
				}

				while (!dq.empty() && dq.back().first >= x)
				{
					dq.pop_back();
				}

				dq.push_back({ x, i });
			}

			cout << dq.front().first << " ";
		}

		return 0;
	}
};