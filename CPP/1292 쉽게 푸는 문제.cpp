// https://www.acmicpc.net/problem/1292

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1292
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int g[1001];

		int v = 1;
		for (int i = 1; i <= 1000; i += v, v += 1)
		{
			for (int j = 0; j < i; ++j)
			{
				if (i + j > 1000)
				{
					break;
				}

				g[i + j] = v;
			}
		}

		int a, b;
		cin >> a >> b;
		int sum = 0;
		for (int i = a; i <= b; ++i)
		{
			sum += g[i];
		}
		cout << sum;
		return 0;
	}
};