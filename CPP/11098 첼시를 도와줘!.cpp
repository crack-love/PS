// https://www.acmicpc.net/problem/11098

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p11098
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		while (n--)
		{
			int p;
			cin >> p;

			int maxv = INT_MIN;
			string maxp;
			for1(i, p)
			{
				int v;
				cin >> v;
				string s;
				cin >> s;
				if (i == 0)
				{
					maxv = v;
					maxp = s;
				}
				else if (v > maxv)
				{
					maxv = v;
					maxp = s;
				}
			}
			cout << maxp << "\n";
		}

		return 0;
	}
};