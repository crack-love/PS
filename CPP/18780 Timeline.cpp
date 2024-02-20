// https://www.acmicpc.net/problem/18780

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p18780
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m, c;
		cin >> n >> m >> c;

		const int SIZE = (int)1e5 + 1;
		int d[SIZE]{};
		for1(i, n)
		{
			cin >> d[i + 1];
		}

		vector<pair<int, int>> next[SIZE];
		int pcnt[SIZE]{};
		for1(i, c)
		{
			int a, b, x;
			cin >> a >> b >> x;
			next[a].push_back({ b,x });
			pcnt[b] += 1;
		}

		queue<int> q;
		for1(i, n)
		{
			if (pcnt[i + 1] <= 0)
				q.push(i + 1);
		}

		while (q.size() > 0)
		{
			int x = q.front();
			q.pop();

			for (auto& [nx, nd] : next[x])
			{
				d[nx] = max(d[nx], d[x] + nd);
				pcnt[nx] -= 1;
				if (pcnt[nx] == 0)
				{
					q.push(nx);
				}
			}
		}

		for1(i, n)
		{
			cout << d[i + 1] << endl;
		}

		return 0;
	}
};