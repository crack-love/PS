// https://www.acmicpc.net/problem/10836

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define x first
#define y second
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p10836
{
	int main()
	{
		fastio;

		int m, n;
		cin >> m >> n;
		int d[1401]{ 1, };
		while (n--)
		{
			int csum = 0;
			for1(i, 3)
			{
				int c;
				cin >> c;
				csum += c;
				d[csum] += 1;
			}
		}

		// x = m-1 ~ 0, y = 0 ~ m-1
		int g[1400]{};
		int sum = 0;
		for1(i, m * 2 - 1)
		{
			sum += d[i];
			g[i] = sum;
		}

		for2(i, j, m, m)
		{
			if (i == 0)
			{
				cout << g[m + j - 1];
			}
			else if (j == 0)
			{
				cout << g[m - i - 1];
			}
			else
			{
				cout << max(g[m - i - 1], g[m + j - 1]);
			}

			cout << (j < m - 1 ? " " : "\n");
		}
	}

};