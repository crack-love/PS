// https://www.acmicpc.net/problem/2485

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p2485
{
	int gcd(int a, int b)
	{
		if (a < b)
			swap(a, b);
		if (b <= 0)
			return a;

		return gcd(b, a % b);
	}

	int main()
	{
		fastio;

		int n;
		cin >> n;
		int a[(int)1e5];
		cin >> a[0] >> a[1];
		int mgcd = a[1] - a[0];
		for (int i = 2; i < n; ++i)
		{
			cin >> a[i];
			mgcd = gcd(mgcd, a[i] - a[i - 1]);
		}

		int ans = 0;
		for1(i, n - 1)
		{
			ans += ((a[i + 1] - a[i]) - mgcd) / mgcd;
		}
		cout << ans;
		return 0;
	}
};