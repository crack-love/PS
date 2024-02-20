// https://www.acmicpc.net/problem/16928

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p16928
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		int laddr[100]{};
		int snake[100]{};

		cin >> n >> m;
		for1(i, n)
		{
			int a, b;
			cin >> a >> b;
			laddr[a] = b;
		}
		for1(i, m)
		{
			int a, b;
			cin >> a >> b;
			snake[a] = b;
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		bool visited[100]{};
		q.push({ 0,1 });
		visited[0] = true;
		bool succeed = false;
		while (!q.empty() && !succeed)
		{
			auto [c, x] = q.top();
			q.pop();

			for1(i, 6)
			{
				int nx = x + i + 1;
				if (nx >= 100)
				{
					cout << c + 1;
					succeed = true;
					break;
				}

				if (laddr[nx] != 0)
				{
					nx = laddr[nx];
				}
				if (snake[nx] != 0)
				{
					nx = snake[nx];
				}

				if (!visited[nx])
				{
					visited[nx] = true;
					q.push({ c + 1, nx });
				}
			}
		}

		return 0;
	}
};