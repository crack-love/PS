// https://www.acmicpc.net/problem/17390

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p17390
{
	int main()
	{
		fastio;

		int n, q;
		cin >> n >> q;
		vector<int> a(n, 0);
		for1(i, n)
		{
			cin >> a[i];
		}

		sort(all(a));
		for (int i = 1; i < n; ++i)
		{
			a[i] += a[i - 1];
		}

		for1(i, q)
		{
			int l, r;
			cin >> l >> r;
			l -= 1;
			r -= 1;
			int ans = a[r] - (l == 0 ? 0 : a[l - 1]);
			cout << ans << "\n";
		}

		return 0;
	}
};