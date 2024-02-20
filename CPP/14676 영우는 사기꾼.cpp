// https://www.acmicpc.net/problem/14676

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p14676
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m, k;
		cin >> n >> m >> k;

		const int SIZE = (int)1e5 + 1;
		vector<int> next[SIZE];
		int pcnt[SIZE]{};
		for1(i, m)
		{
			int x, y;
			cin >> x >> y;
			next[x].push_back(y);
			pcnt[y] += 1;
		}

		int cnt[SIZE]{};
		for1(i, k)
		{
			int o, v;
			cin >> o >> v;

			if (o == 1)
			{
				if (pcnt[v] > 0)
				{
					cout << "Lier!";
					return 0;
				}

				if (++cnt[v] == 1)
				{
					for (int nv : next[v])
					{
						pcnt[nv] -= 1;
					}
				}
			}
			else if (o == 2)
			{
				if (--cnt[v] < 0)
				{
					cout << "Lier!";
					return 0;
				}

				if (cnt[v] == 0)
				{
					for (int nv : next[v])
					{
						pcnt[nv] += 1;
					}
				}
			}
		}

		cout << "King-God-Emperor";

		return 0;
	}
};