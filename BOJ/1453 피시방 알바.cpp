// https://www.acmicpc.net/problem/1453

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p1453
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int a[101]{};
		int cnt = 0;
		while (n--)
		{
			int x;
			cin >> x;
			if (a[x] != 0)
			{
				cnt += 1;
			}
			else
			{
				a[x] = 1;
			}
		}

		cout << cnt;

		return 0;
	}
};