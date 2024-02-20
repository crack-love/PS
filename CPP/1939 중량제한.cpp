// https://www.acmicpc.net/problem/1939
// gold4

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct p1939
{
#define max(a,b) (a>b?a:b)

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		bool visit[(int)1e4 + 1];
		vector<pair<int, int>> e[(int)1e4 + 1];
		int n, m;
		int beg, end;
		int minCap = (int)1e9 + 1;
		int maxCap = 0;

		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;

			e[a].push_back({ b, c });
			e[b].push_back({ a, c });

			maxCap = max(c, maxCap);
			minCap = (minCap < c ? minCap : c);
		}
		cin >> beg >> end;

		if (beg == end)
		{
			cout << 0;
			return 0;
		}

		int l = minCap;
		int r = maxCap + 1;
		while (l < r - 1)
		{
			int m = (l + r) / 2;

			queue<int> q;
			q.push(beg);
			memset(visit, false, sizeof(bool) * (n + 1));
			visit[beg] = true;

			bool finished = false;
			while (!q.empty())
			{
				int x = q.front();
				q.pop();

				for (pair<int, int> p : e[x])
				{
					int y = p.first;
					int cap = p.second;

					if (visit[y]) continue;
					if (m > cap) continue;

					if (y == end)
					{
						finished = true;
						break;
					}

					q.push(y);
					visit[y] = true;
				}
			}

			if (finished)
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}

		cout << l;
		return 0;
	}
};