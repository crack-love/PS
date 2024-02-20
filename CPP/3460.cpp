// https://www.acmicpc.net/problem/3460

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p3460
{
	int main()
	{
		fastio;

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			vector<int> ans;
			int i = 0;
			while (n > 0)
			{
				if ((n & 1) == 1)
					ans.push_back(i);
				n >>= 1;
				i += 1;
			}

			for1(j, ans.size())
			{
				cout << ans[j] << " ";
			}
		}

		return 0;
	}
};