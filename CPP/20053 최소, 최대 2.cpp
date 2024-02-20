// https://www.acmicpc.net/problem/20053

#include <bits/stdc++.h>
#define ll long long
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p20053
{
	int main()
	{
		fastio;

		int t; cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			int l = (int)1e6;
			int g = (int)-1e6;
			for1(i, n)
			{
				int x;
				cin >> x;
				l = min(l, x);
				g = max(g, x);
			}
			cout << l << " " << g << "\n";
		}

		return 0;
	}
};