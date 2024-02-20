// https://www.acmicpc.net/problem/1652

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1652
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		char m[100][100];
		for2(i, j, n, n)
		{
			cin >> m[i][j];
		}

		int row = 0;
		int col = 0;
		for2(i, j, n, n - 1)
		{
			if (m[i][j] == '.' && m[i][j + 1] == '.')
			{
				row += 1;
				while (j < n - 1 && m[i][j] == '.')
				{
					j += 1;
				}
			}
		}

		for2(j, i, n, n - 1)
		{
			if (m[i][j] == '.' && m[i + 1][j] == '.')
			{
				col += 1;
				while (i < n - 1 && m[i][j] == '.')
				{
					i += 1;
				}
			}
		}

		cout << row << " " << col;

		return 0;
	}
};