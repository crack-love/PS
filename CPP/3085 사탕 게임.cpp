// https://www.acmicpc.net/problem/3085

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p3085
{
	int n;
	char a[50][50];
	int answer;

	void countall()
	{
		char col = 0;
		for (int i = 0; i < n; ++i)
		{
			int cnt = 0;
			for (int j = 0; j < n; ++j)
			{
				if (a[i][j] != col)
				{
					col = a[i][j];
					answer = max(answer, cnt);
					cnt = 1;
				}
				else
				{
					cnt += 1;
				}
			}
			answer = max(answer, cnt);
		}
		for (int i = 0; i < n; ++i)
		{
			int cnt = 0;
			for (int j = 0; j < n; ++j)
			{
				if (a[j][i] != col)
				{
					col = a[j][i];
					answer = max(answer, cnt);
					cnt = 1;
				}
				else
				{
					cnt += 1;
				}
			}
			answer = max(answer, cnt);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		for2(i, j, n, n)
		{
			cin >> a[i][j];
		}

		for2(i, j, n, n)
		{
			if (j < n - 1)
			{
				swap(a[i][j], a[i][j + 1]);
				countall();
				swap(a[i][j], a[i][j + 1]);
			}
		}
		for2(i, j, n, n)
		{
			if (i < n - 1)
			{
				swap(a[i][j], a[i + 1][j]);
				countall();
				swap(a[i][j], a[i + 1][j]);
			}
		}
		cout << answer;
		return 0;
	}
};