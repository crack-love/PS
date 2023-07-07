// https://www.acmicpc.net/problem/2212

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p2212
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, k;
		cin >> n >> k;
		int s[(int)1e4]{};
		for1(i, n)
		{
			cin >> s[i];
		}
		sort(s, s + n);

		int d[(int)1e4]{};
		int dsum = 0;
		for1(i, n - 1)
		{
			d[i] = s[i + 1] - s[i];
			dsum += d[i];
		}

		sort(d, d + n - 1, greater<int>());
		for1(i, k - 1)
		{
			dsum -= d[i];
		}

		cout << dsum;
		return 0;
	}
};