// https://www.acmicpc.net/problem/1963

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p1963
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		bool notp[10000]{};

		for (int i = 2; i < 10000; ++i)
		{
			if (!notp[i])
			{
				for (int j = i + i; j < 10000; j += i)
				{
					notp[j] = true;
				}
			}
		}

		int t;
		cin >> t;
		while (t--)
		{
			int x, y;
			cin >> x >> y;
			if (x == y)
			{
				cout << '0' << "\n";
				continue;
			}

			bool finished = false;
			queue<pair<int, int>> q;
			bool visited[10000]{};
			q.push({ x, 0 });
			visited[x] = true;

			while (!q.empty() && !finished)
			{
				auto [a, c] = q.front();
				q.pop();

				int lv = 1;
				for (int i = 0; i < 4; ++i)
				{
					int v = (a / lv) % 10;
					int b = a - v * lv;

					for (int j = 0; j <= 9; ++j)
					{
						int na = b + (j * lv);
						if (na < 1000 || na >= 10000) continue;
						if (visited[na]) continue;
						if (notp[na]) continue;

						if (na == y)
						{
							cout << c + 1 << "\n";
							i = 9;
							j = 4;
							finished = true;
							break;
						}
						else
						{
							visited[na] = true;
							q.push({ na, c + 1 });
						}
					}
					lv *= 10;
				}
			}

			if (!finished)
			{
				cout << "Impossible" << "\n";
			}
		}

		return 0;
	}
};