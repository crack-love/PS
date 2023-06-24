// https://www.acmicpc.net/problem/1062

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p1062
{
	int n, k;
	int w[50];
	int maxCnt = 0;

	void dfs(int i, int ok, int kc)
	{
		if (kc >= k)
		{
			int cnt = 0;
			for1(j, n)
			{
				if ((w[j] & ok) == w[j])
					cnt += 1;
			}

			maxCnt = max(cnt, maxCnt);
			return;
		}
		else if (26 - i < k - kc) // 남은 < 필요
		{
			return;
		}

		if ((ok & (1 << i)) == 0)
		{
			dfs(i + 1, ok | (1 << i), kc + 1);
		}

		dfs(i + 1, ok, kc);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		//freopen("1062.txt", "r", stdin);

		cin >> n >> k;
		for1(i, n)
		{
			string s;
			cin >> s;
			for1(j, s.size())
			{
				w[i] |= 1 << (s[j] - 'a');
			}
		}

		if (k < 5)
		{
			cout << 0;
			return 0;
		}

		int b = 0;
		b |= 1 << ('a' - 'a');
		b |= 1 << ('n' - 'a');
		b |= 1 << ('t' - 'a');
		b |= 1 << ('i' - 'a');
		b |= 1 << ('c' - 'a');
		dfs(0, b, 5);

		cout << maxCnt;

		return 0;
	}
};