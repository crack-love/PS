// https://www.acmicpc.net/problem/15720

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p15720
{
	int main()
	{
		fastio;

		int b, c, d;
		cin >> b >> c >> d;
		vector<int>bs(b, 0);
		vector<int>cs(c, 0);
		vector<int>ds(d, 0);
		ll sum = 0;
		for1(i, b)
		{
			cin >> bs[i];
			sum += bs[i];
		}
		for1(i, c)
		{
			cin >> cs[i];
			sum += cs[i];
		}
		for1(i, d)
		{
			cin >> ds[i];
			sum += ds[i];
		}
		sort(all(bs), greater<int>());
		sort(all(cs), greater<int>());
		sort(all(ds), greater<int>());

		ll dcsum = 0;
		int minsize = min(min(b, c), d);
		for (int i = 0; i < minsize; ++i)
		{
			dcsum += (ll)bs[i] + cs[i] + ds[i];
		}

		ll ans = (sum - dcsum) + dcsum * 9 / 10;

		cout << sum << "\n" << ans;
		return 0;
	}
};