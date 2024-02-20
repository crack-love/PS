// https://www.acmicpc.net/problem/15685

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p15685
{
	int m[101][101];
	const int dx[4] = { 1, 0, -1, 0 };
	const int dy[4] = { 0, -1, 0, 1 };

	void drawrec(int& x, int& y, vector<int>& v)
	{
		for (int i = v.size() - 1; i >= 0; --i)
		{
			int d = (v[i] + 1) % 4;
			m[y][x] = 1;
			x = x + dx[d];
			y = y + dy[d];
			m[y][x] = 1;
			v.push_back(d);
		}
	}

	void draw(int& x, int& y, int g, int d, vector<int>& v)
	{
		if (g == 0)
		{
			m[y][x] = 1;
			x = x + dx[d];
			y = y + dy[d];
			m[y][x] = 1;
			v.push_back(d);
		}
		else
		{
			draw(x, y, g - 1, d, v);
			drawrec(x, y, v);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int x, y, d, g;
			cin >> x >> y >> d >> g;
			vector<int> v;
			draw(x, y, g, d, v);
		}

		int answer = 0;
		for2(i, j, 100, 100)
		{
			if (m[i][j] == 1 &&
				m[i][j + 1] == 1 &&
				m[i + 1][j] == 1 &&
				m[i + 1][j + 1] == 1)
			{
				answer += 1;
			}
		}
		cout << answer;

		return 0;
	}
};