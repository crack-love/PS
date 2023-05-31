// https://www.acmicpc.net/problem/12851

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dd[2][4] = { {0,0,1,-1}, { 1,-1,0,0 } };
using namespace std;

struct p12851
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, k;
		cin >> n >> k;

		const int SIZE = 100'000 + 1;
		int mint[SIZE]{};
		int minc[SIZE]{};
		fill(mint, mint + SIZE, SIZE);

		queue<pair<int, int>> q;
		mint[n] = 0;
		minc[n] = 1;
		q.push({ n, 0 });

		while (q.size() > 0)
		{
			auto [x, t] = q.front();
			q.pop();

			if (t > mint[k])
				break;

			int nt = t + 1;
			for (int nx : {x + 1, x - 1, x * 2})
			{
				step(nx, 0, SIZE, 1);
				if (mint[nx] >= nt)
				{
					minc[nx] = mint[nx] == nt ? minc[nx] + 1 : 1;
					mint[nx] = nt;
					q.push({ nx, nt });
				}
			}
		}

		cout << mint[k] << "\n" << minc[k];

		return 0;
	}
};