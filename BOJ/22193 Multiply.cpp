// https://www.acmicpc.net/problem/22193

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p22193
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		cin >> n >> m;

		string a, b;
		cin >> a >> b;
		vector<int> r((int)1e5, 0);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				r[i + j] += (a[i] - '0') * (b[j] - '0');
			}
		}

		int front = 0;
		for (int i = n + m - 1; i >= 0; --i)
		{
			if (r[i] >= 10)
			{
				if (i == 0)
				{
					front = r[i] / 10;
					r[i] %= 10;
				}
				else
				{
					r[i - 1] += r[i] / 10;
					r[i] %= 10;
				}
			}
		}

		if (front != 0)
		{
			cout << front;
		}

		bool leadingZero = front == 0;
		for (int i = 0; i < n + m - 1; ++i)
		{
			if (r[i] == 0 && leadingZero)
				continue;
			else
				leadingZero = false;

			cout << r[i];
		}

		if (leadingZero)
			cout << 0;

		return 0;
	}
};