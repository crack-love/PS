// https://www.acmicpc.net/problem/2447

#include <iostream>
using namespace std;

struct p2447
{
	int m[6561][6561];
	int dx[8] = { 0, 0, 0, 1, 2, 2, 2, 1 };
	int dy[8] = { 0, 1, 2, 2, 2, 1, 0, 0 };

	void star(int i, int j, int n)
	{
		if (n == 1)
		{
			m[i][j] = 1;
			return;
		}

		for (int k = 0; k < 8; ++k)
		{
			int nx = i + dx[k] * (n / 3);
			int ny = j + dy[k] * (n / 3);
			star(nx, ny, n / 3);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cout.tie(0);

		int n;
		cin >> n;
		star(0, 0, n);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << (m[i][j] ? "*" : " ");
			}
			cout << "\n";
		}
		return 0;
	}
};