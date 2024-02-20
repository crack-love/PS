// https://www.acmicpc.net/problem/1937

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1937
{
	int n;
	int a[500][500];
	int dp[500][500];
	const int dx[4] = { 0,0,1,-1 };
	const int dy[4] = { 1,-1,0,0 };

	int dfs(int x, int y)
	{
		int& ret = dp[x][y];
		if (ret != 0)
		{
			return ret;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			step(nx, ny, n, n);
			if (a[nx][ny] <= a[x][y]) continue;
			ret = max(ret, dfs(nx, ny) + 1);
		}
		return ret;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		for2(i, j, n, n)
		{
			cin >> a[i][j];
		}

		int answer = 0;
		for2(i, j, n, n)
		{
			answer = max(answer, dfs(i, j) + 1);
		}

		cout << answer;
		return 0;
	}
};