// https://www.acmicpc.net/problem/4562

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p4562
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		while (n--)
		{
			int x, y;
			cin >> x >> y;
			if (x >= y)
			{
				cout << "MMM BRAINS\n";
			}
			else
			{
				cout << "NO BRAINS\n";
			}
		}

		return 0;
	}
};