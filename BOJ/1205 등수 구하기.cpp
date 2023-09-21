// https://www.acmicpc.net/problem/1205

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p1205
{
	int main()
	{
		fastio;

		int n, v, p;
		cin >> n >> v >> p;
		int a[50]{};
		fill(a, a + 50, INT_MIN);
		for1(i, n)
		{
			cin >> a[i];
		}

		for1(i, p)
		{
			if (v > a[i])
			{
				cout << i + 1;
				return 0;
			}
			else if (v == a[i])
			{
				for (int j = i + 1; j < p; ++j)
				{
					if (v > a[j])
					{
						cout << i + 1;
						return 0;
					}
				}

				break;
			}
		}

		cout << -1;
		return 0;
	}
};