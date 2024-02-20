// https://www.acmicpc.net/problem/22938

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p22938
{
	int main()
	{
		fastio;

		ll x1, y1, r1;
		ll x2, y2, r2;
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;

		ll sd = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		ll srd = (r1 + r2) * (r1 + r2);
		if (sd < srd)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}

		return 0;
	}
};