// https://www.acmicpc.net/problem/18138
// platinum5

#include<iostream>
#include<cstring>
#include <vector>
using namespace std;

struct p18138
{
	vector<int> edge[200];
	bool visited[200];
	int par[200];

	bool tryLink(int x)
	{
		visited[x] = true;
		for (int e : edge[x])
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
		// w/2 <= x <= w*3/4
		// w <= x <= w*5/4

		int ww[200] = {};
		int n, m; // [1 200]
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> ww[i];
		}
		for (int i = 0; i < m; ++i)
		{
			int w1;
			cin >> w1;
			for (int j = 0; j < n; ++j)
			{
				int w0 = ww[j];
				if (w0 / 2.0 <= w1 && w1 <= w0 * 3.0 / 4)
				{
					edge[j].push_back(i);
				}
				else if (w0 <= w1 && w1 <= w0 * 5.0 / 4)
				{
					edge[j].push_back(i);
				}
			}
		}

		memset(par, -1, sizeof par);

		int answer = 0;
		for (int i = 0; i < n; ++i)
		{
			memset(visited, 0, sizeof visited);

			if (tryLink(i))
			{
				++answer;
			}
		}

		cout << answer;
		return 0;
	}
};