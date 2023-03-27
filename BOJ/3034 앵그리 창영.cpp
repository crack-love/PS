// https://www.acmicpc.net/problem/3034

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p3034
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		int w, h;
		cin >> n >> w >> h;

		int l = floor(sqrt(w * w + h * h));

		for1(i, n)
		{
			int x;
			cin >> x;
			if (x <= l)
			{
				cout << "DA\n";
			}
			else
			{
				cout << "NE\n";
			}
		}

		return 0;
	}
};