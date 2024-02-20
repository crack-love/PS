// https://www.acmicpc.net/problem/1707

#include <bits/stdc++.h>
using namespace std;

struct p1707
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		const int MAX_V = (int)2e4 + 1;
		vector<int> edge[MAX_V]{};
		int visit[MAX_V]{};

		int k;
		cin >> k;
		while (k--)
		{
			int n, e;
			cin >> n >> e;
			memset(visit, 0, sizeof(visit));
			for (int i = 1; i <= n; ++i)
			{
				edge[i].clear();
			}

			for (int i = 0; i < e; ++i)
			{
				int a, b;
				cin >> a >> b;
				edge[a].push_back(b);
				edge[b].push_back(a);
			}

			bool bBiparAssert = true;
			stack<pair<int, int>> s;
			for (int i = 1; i <= n && bBiparAssert; ++i)
			{
				if (visit[i] == 0)
				{
					s.push({ i, 1 });
					while (!s.empty() && bBiparAssert)
					{
						auto [x, c] = s.top(); s.pop();
						int nc = 1 + (c % 2);
						for (int nx : edge[x])
						{
							if (visit[nx] != 0)
							{
								if (visit[nx] != nc)
								{
									bBiparAssert = false;
									break;
								}
							}
							else
							{
								visit[nx] = nc;
								s.push({ nx, nc });
							}
						}
					}
				}
			}

			cout << (bBiparAssert ? "YES" : "NO") << "\n";
		}

		return 0;
	}
};