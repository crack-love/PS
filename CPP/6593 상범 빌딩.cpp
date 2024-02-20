// https://www.acmicpc.net/problem/6593

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p6593
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		char g[30][30][30];
		int bi, bj, bk;

		while (true)
		{
			int l, r, c;
			cin >> l >> r >> c;
			if (l == 0 && r == 0 && c == 0)
				break;

			for1(i, l)
			{
				for2(j, k, r, c)
				{
					char x;
					cin >> x;
					g[i][j][k] = x;
					if (x == 'S')
					{
						bi = i;
						bj = j;
						bk = k;
					}
				}
			}

			bool visited[30][30][30]{};
			queue<tuple<int, int, int, int>> q;
			q.push({ bi,bj,bk, 0 });
			visited[bi][bj][bk] = true;
			const int di[6] = { 1,-1, };
			const int dj[6] = { 0,0,1,-1, };
			const int dk[6] = { 0,0,0,0,1,-1, };

			bool finished = false;
			while (!q.empty() && !finished)
			{
				auto [i, j, k, cnt] = q.front();
				q.pop();

				for1(u, 6)
				{
					int ni = i + di[u];
					int nj = j + dj[u];
					int nk = k + dk[u];
					step(nj, nk, r, c);
					if (ni < 0 || ni >= l) continue;
					if (g[ni][nj][nk] == '#') continue;
					if (visited[ni][nj][nk]) continue;

					if (g[ni][nj][nk] == 'E')
					{
						finished = true;
						cout << "Escaped in " << cnt + 1 << " minute(s).\n";
						break;
					}
					else
					{
						q.push({ ni,nj,nk,cnt + 1 });
						visited[ni][nj][nk] = true;
					}
				}
			}

			if (!finished)
			{
				cout << "Trapped!\n";
			}
		}

		return 0;
	}
};