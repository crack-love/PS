// https://www.acmicpc.net/problem/17388

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p17388
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int s, k, h;
		cin >> s >> k >> h;

		if (s + k + h >= 100)
		{
			cout << "OK";
		}
		else
		{
			if (s < k && s < h)
			{
				cout << "Soongsil";
			}
			else if (k < s && k < h)
			{
				cout << "Korea";
			}
			else
			{
				cout << "Hanyang";
			}
		}

		return 0;
	}
};