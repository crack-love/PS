// https://www.acmicpc.net/problem/20040

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p20040_slow
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		//freopen("20040 in1.txt", "r", stdin);

		int n, m;
		cin >> n >> m;

		int g[(int)5e5 + 1]{};
		int ng = 1;
		vector<vector<int>> glist{ {} };
		for1(i, m)
		{
			int a, b;
			cin >> a >> b;

			// new group
			if (g[a] == 0 && g[b] == 0)
			{
				g[a] = g[b] = ng++;
				glist.push_back({ a, b });
			}
			// add to group
			else if (g[a] != 0 && g[b] == 0)
			{
				g[b] = g[a];
				glist[g[a]].push_back(b);
			}
			else if (g[b] != 0 && g[a] == 0)
			{
				g[a] = g[b];
				glist[g[b]].push_back(a);
			}
			// merge group
			else if (g[a] != g[b])
			{
				int sg = g[b], dg = g[a];
				for (int v : glist[sg])
				{
					glist[dg].push_back(v);
					g[v] = dg;
				}
			}
			// cycle
			else if (g[a] == g[b])
			{
				cout << i + 1;
				return 0;
			}
		}

		cout << 0;
		return 0;
	}
};