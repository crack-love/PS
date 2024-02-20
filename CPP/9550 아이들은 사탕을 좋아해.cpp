// https://www.acmicpc.net/problem/9550

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p9550
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int n, k;
			cin >> n >> k;
			int ans = 0;
			for1(i, n)
			{
				int x;
				cin >> x;
				ans += x / k;
			}

			cout << ans << "\n";
		}

		return 0;
	}
};