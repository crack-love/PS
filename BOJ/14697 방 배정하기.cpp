// https://www.acmicpc.net/problem/14697

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p14697
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int a, b, c;
		cin >> a >> b >> c;
		int n;
		cin >> n;

		for (int i = 0; i < 300; ++i)
		{
			if (a * i > n)
				break;

			for (int j = 0; j < 300; ++j)
			{
				if (b * j > n)
					break;

				for (int k = 0; k < 300; ++k)
				{
					if (c * k > n)
						break;

					if (a * i + b * j + c * k == n)
					{
						cout << 1;
						return 0;
					}
				}
			}
		}

		cout << 0;
		return 0;
	}
};