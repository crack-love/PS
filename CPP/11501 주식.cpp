// https://www.acmicpc.net/problem/11501

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p11501
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			int a[(int)1e6];
			for1(i, n)
			{
				cin >> a[i];
			}

			long long ans = 0;
			int mv = 0;
			for1(i, n)
			{
				int v = a[n - i - 1];
				if (v < mv)
				{
					ans += (long long)mv - v;
				}
				else if (v > mv)
				{
					mv = v;
				}
			}

			cout << ans << "\n";
		}

		return 0;
	}
};