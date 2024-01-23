// https://www.acmicpc.net/problem/18429

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p18429
{
	int n, k;
	int a[8];
	int visited[8];
	int ans = 0;
	int remain = 0;
	void dfs(int i)
	{
		if (i >= n)
		{
			ans += 1;
		}

		for1(j, n)
		{
			if (visited[j])
				continue;

			if (remain - k + a[j] >= 0)
			{
				remain = remain - k + a[j];
				visited[j] = 1;
				dfs(i + 1);
				visited[j] = 0;
				remain = remain + k - a[j];
			}
		}
	}

	int main()
	{
		fastio;
		cin >> n >> k;
		for1(i, n)
		{
			cin >> a[i];
		}

		dfs(0);
		cout << ans;

		return 0;
	}
};