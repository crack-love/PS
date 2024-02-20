// https://www.acmicpc.net/problem/2191
// platinum4

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

struct p2191
{
	vector<int> edges[100];
	bool visited[100];
	int par[100];

	bool tryLink(int x)
	{
		visited[x] = true;

		for (int e : edges[x])
		{
			int p = par[e];

			if (p == -1 || (!visited[p] && tryLink(p)))
			{
				par[e] = x;
				return true;
			}
		}
		return false;
	}

	int main()
	{
		// s초 안(<=)에 들어갈 수 있는 굴 엣지 연결
		// 이분 매칭

		// get inputs
		vector<pair<double, double>> rats;
		int n, m, s, v; // [1 100]
		cin >> n >> m >> s >> v;
		int ss = s * s;
		int vv = v * v;
		for (int i = 0; i < n + m; ++i)
		{
			double x, y;
			cin >> x >> y;
			if (i < n)
			{
				rats.push_back({ x, y });
			}
			else
			{
				// set edges
				for (int j = 0; j < n; ++j)
				{
					double rx = rats[j].first;
					double ry = rats[j].second;
					double dd = (rx - x) * (rx - x) + (ry - y) * (ry - y);

					if (dd / vv <= ss)
					{
						edges[j].push_back(i - n);
					}
				}
			}
		}

		memset(par, -1, sizeof par);

		int ans = n;
		for (int i = 0; i < n; ++i)
		{
			memset(visited, 0, sizeof visited);

			if (tryLink(i))
			{
				ans -= 1;
			}
		}

		// 잡아먹히는 수
		cout << ans;
		return 0;
	}
};