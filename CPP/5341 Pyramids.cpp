// https://www.acmicpc.net/problem/5341

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p5341
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		while (true)
		{
			int x;
			cin >> x;
			if (x == 0)
				break;

			if (x % 2 == 0)
			{
				cout << (x + 1) * (x / 2) << "\n";
			}
			else
			{
				x -= 1;
				cout << (x + 1) * (x / 2) + (x + 1) << "\n";
			}
		}

		return 0;
	}
};