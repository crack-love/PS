// https://www.acmicpc.net/problem/15684

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dd[2][4] = { {0,0,1,-1}, { 1,-1,0,0 } };
using namespace std;

struct p15684
{
	int n, h;
	int e[31][11]{};
	int maxans = 3;
	int ans = maxans + 1;

	bool isSuccess()
	{
		bool success = true;
		for (int u = 1; u <= n; ++u)
		{
			int py = u;
			for (int v = 1; v <= h; ++v)
			{
				if (e[v][py] == 1)
				{
					py += 1;
				}
				else if (e[v][py] == 2)
				{
					py -= 1;
				}
			}
			if (py != u)
			{
				success = false;
				break;
			}
		}
		return success;
	}

	void solve(int i, int j, int cnt)
	{
		if (e[i][j] == 0 && e[i][j + 1] == 0)
		{
			cnt += 1;
			if (cnt > maxans)
				return;
			e[i][j] = 1;
			e[i][j + 1] = 2;

			if (isSuccess())
			{
				ans = min(ans, cnt);

				e[i][j] = 0;
				e[i][j + 1] = 0;
				return;
			}
			else
			{
				solve(i, j, cnt);
			}

			e[i][j] = 0;
			e[i][j + 1] = 0;
			cnt -= 1;
		}

		j += 1;
		if (j >= n)
		{
			i += 1;
			j = 1;
			if (i > h)
			{
				return;
			}
		}

		solve(i, j, cnt);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int m;
		cin >> n >> m >> h;
		for1(i, m)
		{
			int a, b;
			cin >> a >> b;
			e[a][b] = 1;
			e[a][b + 1] = 2;
		}

		if (isSuccess())
		{
			cout << 0;
		}
		else
		{
			solve(1, 1, 0);
			cout << (ans > maxans ? -1 : ans);
		}

		return 0;
	}
};