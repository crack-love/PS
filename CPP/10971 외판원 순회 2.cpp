// https://www.acmicpc.net/problem/10971
// silver2

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

struct p10971
{
	typedef tuple<int, int, int> tp;

	class cmp
	{
	public:
		bool operator()(const tp& x, const tp& y)
		{
			return get<2>(x) > get<2>(y);
		}
	};

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int e[10][10];
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> e[i][j];
			}
		}

		priority_queue<tp, vector<tp>, cmp> q;
		q.push({ 0, 0, 0 });
		while (!q.empty())
		{
			int x = get<0>(q.top());
			int visit = get<1>(q.top());
			int cost = get<2>(q.top());
			q.pop();

			if (x == 0 && visit == (1 << n) - 1)
			{
				cout << cost;
				return 0;
			}

			for (int i = 0; i < n; ++i)
			{
				if (visit & (1 << i)) continue;
				if (i == x) continue;

				if (e[x][i])
				{
					int nvisit = visit | (1 << i);
					int ncost = cost + e[x][i];

					q.push({ i, nvisit, ncost });
				}
			}
		}

		return 0;
	}
};