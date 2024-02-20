// https://www.acmicpc.net/problem/25704

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p25704
{
	int main()
	{
		fastio;

		int n;
		cin >> n;
		int p;
		cin >> p;
		int ans = p;
		if (n >= 5)
		{
			ans = min(ans, p - 500);
		}
		if (n >= 10)
		{
			ans = min(ans, p * 9 / 10);
		}
		if (n >= 15)
		{
			ans = min(ans, p - 2000);
		}
		if (n >= 20)
		{
			ans = min(ans, p * 75 / 100);
		}

		cout << max(ans, 0);

		return 0;
	}
};