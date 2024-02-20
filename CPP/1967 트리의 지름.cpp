// https://www.acmicpc.net/problem/1967

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1967
{
	int n;
	vector<pair<int, int>> childs[10001];
	unordered_map<int, int> length[10001];

	int getlength(int i, int j, int c)
	{
		auto it = length[i].find(j);
		if (it != length[i].end())
		{
			return it->second;
		}
		else
		{
			// j to k
			int ret = c;
			for (pair<int, int> p : childs[j])
			{
				int len = getlength(j, p.first, p.second) + c;
				ret = max(len, ret);
			}

			length[i][j] = ret;
			return ret;
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			childs[a].push_back({ b, c });
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			int len0 = 0;
			int len1 = 0;
			for (pair<int, int> p : childs[i])
			{
				int len = getlength(i, p.first, p.second);
				if (len > len0)
				{
					len1 = len0;
					len0 = len;
				}
				else if (len > len1)
				{
					len1 = len;
				}
			}
			if (len0 + len1 > ans)
			{
				ans = len0 + len1;
			}
		}

		cout << ans;
		return 0;
	}
};