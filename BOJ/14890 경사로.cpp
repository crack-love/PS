// https://www.acmicpc.net/problem/14890

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p14890
{
	int n, l;
	int a[100][100];
	int ans = 0;

	bool getSwap = false;
	int get(int i, int j)
	{
		if (getSwap) swap(i, j);
		return a[i][j];
	}

	void line(int i)
	{
		int ph = get(i, 0);
		bool building = false;
		int cnt = 0;

		for (int j = 0; j < n; ++j)
		{
			int ch = get(i, j);

			if (abs(ch - ph) > 1)
			{
				return;
			}
			else if (building)
			{
				if (ch != ph)
				{
					return;
				}
				else
				{
					cnt -= 1;
					if (cnt == 0)
					{
						building = false;
					}
				}
			}
			// move up
			else if (ch > ph)
			{
				if (cnt < l)
				{
					return;
				}
				else
				{
					cnt = 1;
					ph = ch;
				}
			}
			// move down
			else if (ch < ph)
			{
				cnt = l - 1;
				ph = ch;
				if (cnt > 0)
				{
					building = true;
				}
			}
			else if (ch == ph)
			{
				cnt += 1;
			}
		}

		if (building && cnt == 0)
		{
			building = false;
		}

		if (!building)
		{
			ans += 1;
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n >> l;
		for2(i, j, n, n)
		{
			cin >> a[i][j];
		}

		for (int i = 0; i < n; ++i)
		{
			line(i);
			getSwap = true;
			line(i);
			getSwap = false;
		}

		cout << ans;
		return 0;
	}
};