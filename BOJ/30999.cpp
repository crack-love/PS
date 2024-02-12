// https://www.acmicpc.net/problem/30999

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p30999
{
	int main()
	{
		fastio;

		int n, m;
		cin >> n >> m;
		int ans = 0;
		for1(i, n)
		{
			string s;
			cin >> s;
			int oc = 0, xc = 0;
			for1(j, s.size())
			{
				if (s[j] == 'O')
				{
					oc += 1;
				}
				else if (s[j] == 'X')
				{
					xc += 1;
				}
			}

			if (oc > xc)
			{
				ans += 1;
			}
		}

		cout << ans;
		return 0;
	}
};