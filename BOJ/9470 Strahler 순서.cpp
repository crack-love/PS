// https://www.acmicpc.net/problem/9470

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p9470
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		vector<pair<int, int>> ans;

		while (t--)
		{
			int k, m, p;
			cin >> k >> m >> p;

			vector<int> next[1001];
			vector<int> prev[1001];
			int pcnt[1001]{};
			for1(i, p)
			{
				int a, b;
				cin >> a >> b;
				next[a].push_back(b);
				prev[b].push_back(a);
				pcnt[b] += 1;
			}

			int stra[1001]{};
			queue<int> q;
			for (int i = 1; i <= m; ++i)
			{
				if (pcnt[i] <= 0)
				{
					q.push(i);
					stra[i] = 1;
				}
			}

			while (q.size() > 0)
			{
				int x = q.front();
				q.pop();

				for (int nx : next[x])
				{
					pcnt[nx] -= 1;
					if (pcnt[nx] == 0)
					{
						for (int px : prev[nx])
						{
							if (stra[px] > stra[nx])
							{
								stra[nx] = stra[px];
							}
							else if (stra[px] == stra[nx])
							{
								stra[nx] = stra[px] + 1;
							}
						}

						q.push(nx);
					}
				}
			}

			ans.push_back({ k, stra[m] });
		}

		for (auto p : ans)
		{
			cout << p.first << " " << p.second << "\n";
		}

		return 0;
	}
};