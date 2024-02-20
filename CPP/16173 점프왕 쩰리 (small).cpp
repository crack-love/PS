// https://www.acmicpc.net/problem/16173

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p16173
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int g[3][3];
		for2(i, j, n, n)
		{
			cin >> g[i][j];
		}

		queue<pair<int, int>> q;
		q.push({ 0,0 });
		while (q.size() > 0)
		{
			auto [x, y] = q.front();
			q.pop();

			if (g[x][y] == -1)
			{
				cout << "HaruHaru";
				return 0;
			}

			if (g[x][y] == 0)
				continue;

			if (x + g[x][y] < n)
				q.push({ x + g[x][y], y });
			if (y + g[x][y] < n)
				q.push({ x, y + g[x][y] });
		}

		cout << "Hing";
		return 0;
	}
};