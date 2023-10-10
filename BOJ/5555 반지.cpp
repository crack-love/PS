// https://www.acmicpc.net/problem/5555

#include <bits/stdc++.h>
#define ll long long
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p5555
{
	int main()
	{
		fastio;

		string q;
		cin >> q;
		int n;
		cin >> n;
		int ans = 0;
		for1(i, n)
		{
			string x;
			cin >> x;

			for1(j, x.size())
			{
				bool found = false;
				for1(k, q.size())
				{
					int j2 = (j + k) % x.size();
					if (x[j2] != q[k])
						break;

					if (k == q.size() - 1)
						found = true;
				}

				if (found)
				{
					ans += 1;
					break;
				}
			}
		}

		cout << ans;
		return 0;
	}
};