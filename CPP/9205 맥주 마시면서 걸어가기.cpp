// https://www.acmicpc.net/problem/9205

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p9205
{
	int n;
	int px[102], py[102];

	bool bfs()
	{
		bool visited[102]{};
		queue<pair<int, int>> q;
		q.push({ px[0], py[0] });
		visited[0] = true;

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == px[n + 1] && y == py[n + 1])
			{
				return true;
			}

			for1(i, n + 2)
			{
				if (visited[i]) continue;
				int d = abs(x - px[i]) + abs(y - py[i]);
				if (d <= 1000)
				{
					q.push({ px[i], py[i] });
					visited[i] = true;
				}
			}
		}
		return false;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		//freopen("9205 in.txt", "r", stdin);
		int t;
		cin >> t;
		while (t--)
		{
			cin >> n;
			for1(i, n + 2)
			{
				cin >> px[i] >> py[i];
			}
			cout << (bfs() ? "happy" : "sad") << "\n";
		}

		return 0;
	}
};