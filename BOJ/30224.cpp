// https://www.acmicpc.net/problem/30224

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p30224
{
	int main()
	{
		fastio;

		int x;
		cin >> x;
		int con7 = false;
		int x1 = x;
		while (x1 > 0)
		{
			if (x1 % 10 == 7)
				con7 = true;
			x1 /= 10;
		}

		int div7 = x % 7 == 0;
		int ans = ((con7 << 1) | div7);
		cout << ans;

		return 0;
	}
};