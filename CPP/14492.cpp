// https://www.acmicpc.net/problem/14492

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p14492
{
	int main()
	{
		fastio;

		int n;
		cin >> n;
		int a[300][300];
		int b[300][300];
		for2(i, j, n, n)
			cin >> a[i][j];
		for2(i, j, n, n)
			cin >> b[i][j];

		int c[300][300]{};
		int ans = 0;
		for2(i, j, n, n)
		{
			for (int k = 0; k < n; ++k)
			{
				c[i][j] |= a[i][k] & b[k][j];
				if (c[i][j])
					break;
			}
			ans += c[i][j];
		}
		cout << ans;
		return 0;
	}
};