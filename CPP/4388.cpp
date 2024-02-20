// https://www.acmicpc.net/problem/4388

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p4388
{
	int main()
	{
		fastio;

		while (true)
		{
			ll a, b;
			cin >> a >> b;
			if (a == 0 && b == 0)
			{
				break;
			}

			int ans = 0;
			int f = 0;
			while (a > 0 || b > 0)
			{
				int am = a % 10;
				int bm = b % 10;
				int v = f + am + bm;
				if (v >= 10)
				{
					ans += 1;
				}
				a /= 10;
				b /= 10;
				f = v / 10;
			}
			cout << ans << "\n";
		}

		return 0;
	}
};