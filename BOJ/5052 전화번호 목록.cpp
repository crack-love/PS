// https://www.acmicpc.net/problem/5052

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
using namespace std;

struct p5052
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string a[10000];
		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			for1(i, n)
			{
				cin >> a[i];
			}
			sort(a, a + n);

			bool ok = true;
			for1(i, n - 1)
			{
				if (a[i + 1].size() < a[i].size())
					continue;

				int isize = a[i].size();
				for1(j, isize)
				{
					if (a[i + 1][isize - j - 1] !=
						a[i][isize - j - 1])
					{
						break;
					}

					if (j == isize - 1)
					{
						ok = false;
						i = n - 1;
						break;
					}
				}
			}

			cout << (ok ? "YES" : "NO") << "\n";
		}

		return 0;
	}
};