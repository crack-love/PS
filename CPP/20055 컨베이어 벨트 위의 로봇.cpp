// https://www.acmicpc.net/problem/20055

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p20055
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, k;
		cin >> n >> k;

		deque<pair<int, int>> q0;
		deque<int> q1;
		int zeCnt = 0;
		int stCnt = 0;

		for1(i, 2 * n)
		{
			int x;
			cin >> x;
			if (x <= 0)
				zeCnt += 1;

			if (i < n)
				q0.push_back({ x, false });
			else
				q1.push_back(x);
		}

		while (zeCnt < k)
		{
			stCnt += 1;

			q0.push_front({ q1.back(), false });
			q1.pop_back();
			q1.push_front(q0.back().first);
			q0.pop_back();

			for (int i = n - 1; i >= 0; --i)
			{
				if (q0[i].second)
				{
					if (i == n - 1)
					{
						q0[i].second = false;
					}
					else if (!q0[i + 1].second && q0[i + 1].first > 0)
					{
						q0[i + 1].first -= 1;
						q0[i + 1].second = true;
						q0[i].second = false;
						if (q0[i + 1].first <= 0)
							zeCnt += 1;
					}
				}
			}

			if (q0[0].first > 0)
			{
				q0[0].first -= 1;
				q0[0].second = true;
				if (q0[0].first <= 0)
					zeCnt += 1;
			}
		}

		cout << stCnt;

		return 0;
	}
};