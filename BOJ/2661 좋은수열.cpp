// https://www.acmicpc.net/problem/2661

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2661
{
	int n;
	bool finished;

	void solve(string& x)
	{
		for (char i = '1'; i <= '3'; ++i)
		{
			x.push_back(i);

			int size = x.size();
			bool isBad = false;
			for (int msize = 1; msize <= size / 2; ++msize)
			{
				isBad = true;
				for (int j = 0; j < msize; ++j)
				{
					if (x[size - 1 - j] != x[size - 1 - j - msize])
					{
						isBad = false;
						break;
					}
				}

				if (isBad) break;
			}

			if (!isBad)
			{
				if (x.size() >= n)
				{
					cout << x;
					finished = true;
					return;
				}

				solve(x);
				if (finished) return;
			}

			x.pop_back();
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		string x;
		solve(x);

		return 0;
	}
};