// https://www.acmicpc.net/problem/5692

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define x first
#define y second
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p5692
{
	int main()
	{
		fastio;

		int f[6]{ 0,1 };
		for (int i = 2; i < 6; ++i)
		{
			f[i] = f[i - 1] * i;
		}

		while (true)
		{
			string x;
			cin >> x;
			if (x == "0")
				break;

			int ans = 0;
			for (int i = 0; i < x.size(); ++i)
			{
				int v = x[i] - '0';
				ans += v * f[x.size() - i];
			}

			cout << ans << "\n";
		}

		return 0;
	}
};