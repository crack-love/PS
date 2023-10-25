// https://www.acmicpc.net/problem/14623

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

struct p14623
{
	int main()
	{
		fastio;

		string a, b;
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int ans[60]{};
		for (int i = 0; i < a.size(); ++i)
		{
			for (int j = 0; j < b.size(); ++j)
			{
				ans[i + j] +=
					(a[i] == '1' ? 1 : 0) *
					(b[j] == '1' ? 1 : 0);
			}
		}

		for (int i = 0; i < 60; ++i)
		{
			if (ans[i] > 1)
			{
				ans[i + 1] += ans[i] / 2;
				ans[i] %= 2;
			}
		}

		bool flushingZero = true;
		for (int i = 59; i >= 0; --i)
		{
			if (flushingZero)
			{
				if (ans[i] == 0)continue;
				else flushingZero = false;
			}
			cout << ans[i];
		}
		if (flushingZero)
		{
			cout << "0";
		}

		return 0;
	}
};