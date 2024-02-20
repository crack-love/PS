// https://www.acmicpc.net/problem/3991

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define x first
#define y second
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p3991
{
	int main()
	{
		fastio;

		int h, w, c;
		cin >> h >> w >> c;
		int cc[9];
		for1(i, c)
		{
			int x;
			cin >> x;
			cc[i] = x;
		}

		int g[10][10];
		int cci = 0;
		bool jdir = 0;
		for (int i = h - 1; i >= 0; --i)
		{
			int jbeg, jend, jdelta;
			if (jdir == 0)
			{
				jbeg = 0;
				jend = w;
				jdelta = 1;
			}
			else
			{
				jbeg = w - 1;
				jend = -1;
				jdelta = -1;
			}

			for (int j = jbeg; j != jend; j += jdelta)
			{
				if (cc[cci] == 0)
				{
					cci += 1;
				}

				g[i][j] = cci + 1;
				cc[cci] -= 1;
			}

			jdir = (jdir + 1) % 2;
		}

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cout << g[i][j];
			}
			cout << "\n";
		}

		return 0;
	}
};