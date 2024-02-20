// https://www.acmicpc.net/problem/1932

#include <iostream>
#include <algorithm>
using namespace std;

struct p1932
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int answer = 0;
		int d[501][501] = {};
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				int x;
				cin >> x;

				int ls = x + d[i - 1][j - 1];
				int rs = x + d[i - 1][j];
				d[i][j] = max(ls, rs);

				answer = max(answer, d[i][j]);
			}
		}

		cout << answer;

		return 0;
	}
};