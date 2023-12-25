// https://www.acmicpc.net/problem/25494

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p25494
{
	int main()
	{
		fastio;

		int t;
		cin >> t;
		while (t--)
		{
			int ans = 0;
			int a, b, c;
			cin >> a >> b >> c;
			for (int i = 1; i <= a; ++i)
				for (int j = 1; j <= b; ++j)
					for (int k = 1; k <= c; ++k)
					{
						if ((i % j == j % k) &&
							(j % k == k % i))
						{
							ans += 1;
						}
					}

			cout << ans << "\n";
		}

		return 0;
	}
};