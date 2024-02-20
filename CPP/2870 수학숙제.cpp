// https://www.acmicpc.net/problem/2870

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2870
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		vector<string> ans;

		while (n--)
		{
			string line;
			cin >> line;

			string num;
			bool needFlush = false;
			for (char c : line)
			{
				if ('0' <= c && c <= '9')
				{
					needFlush = true;

					if (num.size() == 0 && c == '0')
					{
						continue;
					}
					else
					{
						num.push_back(c);
					}
				}
				else if (needFlush)
				{
					needFlush = false;

					if (num.size() == 0)
					{
						ans.push_back("0");
					}
					else
					{
						ans.push_back(num);
						num = "";
					}
				}
			}

			if (needFlush)
			{
				if (num.size() == 0)
				{
					ans.push_back("0");
				}
				else
				{
					ans.push_back(num);
					num = "";
				}
			}
		}

		auto pred = [](const string& a, const string& b)->bool
		{
			if (a.size() == b.size())
			{
				return a < b;
			}
			else
			{
				return a.size() < b.size();
			}
		};

		sort(ans.begin(), ans.end(), pred);

		for1(i, ans.size())
		{
			cout << ans[i] << "\n";
		}

		return 0;
	}
};