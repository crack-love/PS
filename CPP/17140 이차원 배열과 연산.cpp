// https://www.acmicpc.net/problem/17140

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p17140
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int r, c, k;
		cin >> r >> c >> k;
		r -= 1;
		c -= 1;

		int a[100][100]{};
		for2(i, j, 3, 3)
		{
			cin >> a[i][j];
		}

		pair<int, int> cnt[101]{};
		auto cntArr = [&cnt](int* beg, int delta) -> int
		{
			for1(i, 101)
			{
				cnt[i] = { INT_MAX, i };
			}

			int* curr = beg;
			for1(i, 100)
			{
				if (*curr == 0)
				{
					curr += delta;
					continue;
				}

				if (cnt[*curr].first == INT_MAX)
					cnt[*curr].first = 1;
				else
					cnt[*curr].first += 1;

				*curr = 0;
				curr += delta;
			}

			std::sort(cnt, cnt + 101);

			curr = beg;
			int size = 0;
			for1(i, 101)
			{
				if (cnt[i].first == INT_MAX)
					break;

				*curr = cnt[i].second;
				curr += delta;
				*curr = cnt[i].first;
				curr += delta;
				size += 2;

				if (size >= 100)
					break;
			}

			return size;
		};

		int n = 3, m = 3;
		int ans = 0;
		while (true)
		{
			if (a[r][c] == k)
			{
				cout << ans;
				break;
			}
			else if (ans++ > 100)
			{
				cout << -1;
				break;
			}

			if (n >= m)
			{
				m = 0;
				for1(i, n)
				{
					int newm = cntArr(&a[i][0], 1);
					m = max(m, newm);
				}
			}
			else
			{
				n = 0;
				for1(i, m)
				{
					int newn = cntArr(&a[0][i], 100);
					n = max(n, newn);
				}
			}
		}

		return 0;
	}
};