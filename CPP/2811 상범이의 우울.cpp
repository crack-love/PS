// https://www.acmicpc.net/problem/2811

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

struct p2811
{
	int main()
	{
		const int SIZE = (int)1e5 + 1;
		int dur[SIZE]{}; // 3 2 1
		int maxDur = 0;
		int n;
		cin >> n;
		for1(i, n)
		{
			int x;
			cin >> x;
			if (x < 0)
				dur[i] = 1;
		}
		for (int i = n - 1; i >= 0; --i)
		{
			if (dur[i] > 0)
				dur[i] = dur[i + 1] + 1;
			maxDur = max(dur[i], maxDur);
		}

		int ans = 0;
		int t2[SIZE]{}; // 1 2 3
		for1(i, n)
		{
			if (dur[i] == 0 && dur[i + 1] > 0)
			{
				int len = dur[i + 1] * 2;
				for (int j = i; j >= 0 && len > 0; --j)
				{
					if (t2[j] != 1)
					{
						t2[j] = 1;
						ans += 1;
					}
					len -= 1;
				}
			}
		}

		int maxT3 = 0;
		for1(i, n)
		{
			if (dur[i] == 0 && dur[i + 1] > 0 && dur[i + 1] == maxDur)
			{
				int cnt = 0;
				int len = dur[i + 1] * 3;
				for (int j = i; j >= 0 && len > 0; --j)
				{
					if (t2[j] != 1)
						cnt += 1;
					len -= 1;
				}
				maxT3 = max(maxT3, cnt);
			}
		}
		ans += maxT3;

		cout << ans;
		return 0;
	}
};