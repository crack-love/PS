// https://www.acmicpc.net/problem/1740

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p1740
{
	int main()
	{
		fastio;

		ll n;
		cin >> n;
		ll v = 0;
		ll lv = 1;
		while (n > 0)
		{
			if ((n & 1) > 0)
			{
				v += lv;
			}
			lv *= 3;
			n >>= 1;
		}
		cout << v;
		return 0;
	}
};