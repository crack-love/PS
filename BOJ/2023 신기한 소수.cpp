// https://www.acmicpc.net/problem/2023

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2023
{
	int n;

	void dfs(int x, int len)
	{
		int sq = (int)sqrt(x);
		for (int i = 2; i <= sq; ++i)
		{
			if (x % i == 0)
				return;
		}

		if (len == n)
		{
			cout << x << "\n";
			return;
		}

		for (int i = 0; i <= 9; ++i)
		{
			dfs(x * 10 + i, len + 1);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		dfs(2, 1);
		dfs(3, 1);
		dfs(5, 1);
		dfs(7, 1);

		return 0;
	}
};