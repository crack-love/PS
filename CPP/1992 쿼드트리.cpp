// https://www.acmicpc.net/problem/1992

#include <bits/stdc++.h>
using namespace std;

struct p1992
{
	string g[64];
	const int dx[4] = { 0, 0, 1, 1 };
	const int dy[4] = { 0, 1, 0, 1 };

	string enc(int x, int y, int w)
	{
		if (w == 1)
		{
			return { g[x][y] };
		}

		int hw = w / 2;
		string v[4];
		bool bEnc = true;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i] * hw;
			int ny = y + dy[i] * hw;

			v[i] = enc(nx, ny, hw);

			if (v[i].size() > 1 ||
				(i > 0 && v[i][0] != v[i - 1][0]))
			{
				bEnc = false;
			}
		}

		if (bEnc)
		{
			return { v[0][0] };
		}
		else
		{
			string ret;
			ret.push_back('(');
			for (int i = 0; i < 4; ++i)
			{
				ret.append(v[i]);
			}
			ret.push_back(')');
			return ret;
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> g[i];
		}

		cout << enc(0, 0, n);

		return 0;
	}
};