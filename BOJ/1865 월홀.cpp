// https://www.acmicpc.net/problem/1865

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1865
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int n, m, w;
			cin >> n >> m >> w;
			vector<tuple<int, int, int>> edge;
			for1(i, m)
			{
				int s, e, t;
				cin >> s >> e >> t;
				edge.push_back({ s, e, t });
				edge.push_back({ e, s, t });
			}
			for1(i, w)
			{
				int s, e, t;
				cin >> s >> e >> t;
				edge.push_back({ s, e, -t });
			}

			const int MAX = 10000 * 500;
			int visited[501];
			fill(visited, visited + n + 1, MAX);
			visited[1] = 0;
			bool cycle = false;
			for1(i, n + 1)
			{
				for1(j, edge.size())
				{
					auto [s, e, t] = edge[j];
					if (visited[s] + t < visited[e])
					{
						visited[e] = visited[s] + t;
						if (i == n)
						{
							cycle = true;
							break;
						}
					}
				}
			}

			cout << (cycle ? "YES" : "NO") << "\n";
		}

		return 0;
	}
};