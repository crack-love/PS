// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p2810
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int hcnt = 1;
		for1(i, n)
		{
			char x;
			cin >> x;

			if (x == 'L')
			{
				char l2;
				cin >> l2;
				i += 1;
			}

			hcnt += 1;
		}

		cout << min(hcnt, n);
		return 0;
	}
};