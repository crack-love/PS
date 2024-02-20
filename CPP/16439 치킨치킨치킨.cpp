// https://www.acmicpc.net/problem/16439

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p16439
{
	int main()
	{
		fastio;

		int n, m;
		cin >> n >> m;
		int a[30][30];
		for2(i, j, n, m)
		{
			cin >> a[i][j];
		}

		vector<int> b(m, 0);
		b[0] = b[1] = b[2] = 1;

		int ans = 0;
		do
		{
			vector<int> mv(n, 0);
			for1(i, m)
			{
				if (b[i] == 1)
				{
					for1(j, n)
					{
						mv[j] = max(mv[j], a[j][i]);
					}
				}
			}

			int sum = 0;
			for1(i, n)
			{
				sum += mv[i];
			}

			ans = max(ans, sum);
		} while (prev_permutation(all(b)));

		cout << ans;
		return 0;
	}
};