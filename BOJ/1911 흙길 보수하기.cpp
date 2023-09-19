// https://www.acmicpc.net/problem/1911

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

int main()
{
	fastio;

	int n, l;
	cin >> n >> l;
	pii a[10000] {};
	for1(i, n)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {x,y};
	}
	sort(a, a + n);

	int ans = 0;
	int end = 0;
	for1 (i, n)
	{
		if (a[i].second <= end)
			continue;

		int beg = max(a[i].first, end);
		int len = a[i].second - beg;
		int cnt = len / l;
		if (len % l != 0)
			cnt += 1;

		ans += cnt;
		end = beg + cnt * l;
	}

	cout << ans;
	return 0;
}