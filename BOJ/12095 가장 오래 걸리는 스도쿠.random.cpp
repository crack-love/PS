#include <iostream>
#include <random>
#include "12095 가장 오래 걸리는 스토쿠.file.cpp"
using namespace std;

struct p12095_random
{
	int prea[10][10];
	int a[10][10];
	bool c[10][10];
	bool c2[10][10];
	bool c3[10][10];
	int n = 9;
	int cnt = 0;
	int square(int x, int y) {
		return (x / 3) * 3 + (y / 3);
	}
	bool go(int z)
	{
		cnt += 1;
		if (z == 81)
		{
			if (cnt > 30000)
			{
				cout << cnt << "\n";
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						cout << prea[i][j] << ' ';
					}
					cout << '\n';
				}
			}
			return true;
		}
		if (cnt >= 10000000) {
			return true;
		}

		int x = z / n;
		int y = z % n;
		if (a[x][y] != 0) {
			return go(z + 1);
		}
		else {
			for (int i = 1; i <= 9; i++) {
				if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
					c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
					a[x][y] = i;
					if (go(z + 1)) {
						return true;
					}
					a[x][y] = 0;
					c[x][i] = c2[y][i] = c3[square(x, y)][i] = false;
				}
			}
		}
		return false;
	}

	int main()
	{

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(1, 10 + 9);

		int tc = 0;
		while (cnt < 100000)
		{
			cnt = 0;
			++tc;

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					c[i][j] = c2[i][j] = c3[i][j] = 0;
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)
				{
					//cin >> a[i][j];
					int v = dis(gen);
					if (v <= 10)
					{
						a[i][j] = 0;
					}
					else
					{
						a[i][j] = v % 10;
					}

					prea[i][j] = a[i][j];
					if (a[i][j] != 0) {
						c[i][a[i][j]] = true;
						c2[j][a[i][j]] = true;
						c3[square(i, j)][a[i][j]] = true;
					}
				}
			}

			go(0);

			if (tc % 20000 == 0)
			{
				cout << "tc passed " << tc << ", cnt " << cnt << "\n";

				/*for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						cout << prea[i][j] << ' ';
					}
					cout << '\n';
				}
				*/
			}
		}

		cout << "final\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << prea[i][j] << ' ';
			}
			cout << '\n';
		}

		return 0;
	}
};