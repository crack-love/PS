// https://www.acmicpc.net/problem/2623

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2623
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;

		vector<int> next[1001];
		int precnt[1001]{};

		for1(i, m)
		{
			int c;
			cin >> c;
			if (c <= 0) continue;

			int last;
			cin >> last;
			c -= 1;

			while (c--)
			{
				int x;
				cin >> x;
				next[last].push_back(x);
				last = x;
				precnt[x] += 1;
			}
		}

		queue<int> q;
		for (int i = 1; i <= n; ++i)
		{
			if (precnt[i] <= 0)
			{
				q.push(i);
			}
		}

		vector<int> ans;
		while (q.size() > 0)
		{
			int v = q.front();
			q.pop();
			ans.push_back(v);

			for (int nv : next[v])
			{
				precnt[nv] -= 1;
				if (precnt[nv] == 0)
				{
					q.push(nv);
				}
			}
		}

		if (ans.size() >= n)
		{
			for (int v : ans)
			{
				cout << v << "\n";
			}
		}
		else
		{
			cout << 0;
		}

		return 0;
	}
};