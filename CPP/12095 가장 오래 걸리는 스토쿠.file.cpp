#include <iostream>
using namespace std;

struct p12095_file
{
	int a[10][10];
	bool c[10][10];
	bool c2[10][10];
	bool c3[10][10];
	int n = 9;
	int cnt = 0;
	int square(int x, int y) {
		return (x / 3) * 3 + (y / 3);
	}
	bool gof(int z) {
		cnt += 1;
		if (cnt >= 100000000) {
			return true;
		}
		if (z == 81) {
			cout << cnt << "\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << a[i][j] << ' ';
				}
				cout << '\n';
			}
			return true;
		}
		int x = z / n;
		int y = z % n;
		if (a[x][y] != 0) {
			return gof(z + 1);
		}
		else {
			for (int i = 1; i <= 9; i++) {
				if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
					c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
					a[x][y] = i;
					if (gof(z + 1)) {
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
		freopen("12095 가장 오래 걸리는 스도쿠.txt", "r", stdin);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] != 0) {
					c[i][a[i][j]] = true;
					c2[j][a[i][j]] = true;
					c3[square(i, j)][a[i][j]] = true;
				}
			}
		}
		gof(0);
		cout << cnt << " cnt \n";
		return 0;
	}
};