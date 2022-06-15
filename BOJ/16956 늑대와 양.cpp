// https://www.acmicpc.net/problem/16956
// siver3

#include <iostream>
using namespace std;

struct p16956
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		char a[500][501];
		int r, c;
		cin >> r >> c;
		for (int i = 0; i < r; ++i)
		{
			cin >> a[i];
		}

		const int dx[] = { 0, 0, 1, -1 };
		const int dy[] = { 1, -1, 0, 0 };
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if (a[i][j] == 'W')
				{
					for (int k = 0; k < 4; ++k)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

						if (a[nx][ny] == 'S')
						{
							cout << "0\n";
							return 0;
						}
						else if (a[nx][ny] != 'W')
						{
							a[nx][ny] = 'D';
						}
					}
				}
			}
		}

		cout << "1\n";
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cout << a[i][j];
			}
			cout << "\n";
		}

		return 0;
	}
};