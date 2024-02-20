// https://www.acmicpc.net/problem/16235

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dd[2][4] = { {0,0,1,-1}, { 1,-1,0,0 } };
using namespace std;

struct p16235
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m, k;
		cin >> n >> m >> k;

		int a[10][10];
		for2(i, j, n, n)
		{
			cin >> a[i][j];
		}

		int v[10][10];
		deque<int> tree[10][10];
		fill(&v[0][0], &v[n - 1][n], 5);

		for1(i, m)
		{
			int x, y, z;
			cin >> x >> y >> z;
			tree[x - 1][y - 1].push_back(z);
		}

		const int dx[] = { -1,-1,-1,0,0,1,1,1 };
		const int dy[] = { -1,0,1,-1,1,-1,0,1 };
		for1(y, k)
		{
			// spring
			for2(i, j, n, n)
			{
				for (int k = tree[i][j].size() - 1; k >= 0; --k)
				{
					int t = tree[i][j][k];
					if (v[i][j] >= t)
					{
						v[i][j] -= t;
						tree[i][j][k] += 1;
					}
					// summer
					else
					{
						for (int u = k; u >= 0; --u)
						{
							v[i][j] += tree[i][j].front() / 2;
							tree[i][j].pop_front();
						}
						break;
					}
				}
			}

			// fall
			for2(i, j, n, n)
			{
				for1(k, tree[i][j].size())
				{
					int t = tree[i][j][k];
					if (t % 5 == 0)
					{
						for1(u, 8)
						{
							int ni = i + dx[u];
							int nj = j + dy[u];
							step(ni, nj, n, n);

							tree[ni][nj].push_back(1);
						}
					}
				}

				// winter
				v[i][j] += a[i][j];
			}
		}

		int cnt = 0;
		for2(i, j, n, n)
		{
			cnt += tree[i][j].size();
		}
		cout << cnt;

		return 0;
	}
};