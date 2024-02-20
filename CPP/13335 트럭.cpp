// https://www.acmicpc.net/problem/13335

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p13335
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, w, l;
		cin >> n >> w >> l;

		int t = 1;
		int currl = 0;
		queue<pair<int, int>> q; // truckl, endtime
		for1(i, n)
		{
			int x;
			cin >> x;

			while (currl + x > l)
			{
				auto [fl, ft] = q.front();
				q.pop();

				currl -= fl;
				if (ft > t)
				{
					t = ft;
				}
			}

			q.push({ x, t + w });
			currl += x;
			t += 1;
		}

		while (!q.empty())
		{
			if (q.front().second > t)
			{
				t = q.front().second;
			}
			q.pop();
		}

		cout << t;

		return 0;
	}
};