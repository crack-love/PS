// https://www.acmicpc.net/problem/14567

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p14567
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;
		vector<int> next[1001];
		int pcnt[1001]{};
		for1(i, m)
		{
			int a, b;
			cin >> a >> b;
			next[a].push_back(b);
			pcnt[b] += 1;
		}

		queue<pair<int, int>> q;
		for1(i, n)
		{
			if (pcnt[i + 1] <= 0)
			{
				q.push({ i + 1, 1 });
			}
		}

		int s = 1;
		int ans[1001]{};
		while (!q.empty())
		{
			auto [v, c] = q.front();
			q.pop();
			ans[v] = c;

			for (int n : next[v])
			{
				pcnt[n] -= 1;
				if (pcnt[n] == 0)
				{
					q.push({ n, c + 1 });
				}
			}
		}

		for1(i, n)
		{
			cout << ans[i + 1] << " ";
		}

		return 0;
	}
};