// https://www.acmicpc.net/problem/12933

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p12933
{
	int solve()
	{
		string s;
		cin >> s;

		string cmps = "quack";
		int cnts[5] = {};
		int ans = 0;
		int dup = 0;
		for (char c : s)
		{
			for (int j = 0; j < cmps.size(); ++j)
			{
				if (cmps[j] == c)
				{
					if (j == 0)
					{
						dup += 1;
						ans = max(dup, ans);
					}
					else if (j == cmps.size() - 1)
					{
						dup -= 1;
					}

					if (j > 0)
					{
						if (cnts[j - 1] == 0)
						{
							return -1;
						}
						cnts[j - 1] -= 1;
					}

					cnts[j] += 1;
				}
			}
		}

		for (int i = 0; i < cmps.size() - 1; ++i)
		{
			if (cnts[i] > 0)
				return -1;
		}

		return ans;
	}

	int main()
	{
		fastio;
		cout << solve();
		return 0;
	}
};