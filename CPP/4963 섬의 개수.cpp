// https://www.acmicpc.net/problem/4963

#include <bits/stdc++.h>
using namespace std;

struct p4963
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		const int dx[]{ 0, 1, -1 };
		const int dy[]{ 0, 1, -1 };

		while (true)
		{
			int w, h;
			cin >> w >> h;
			if (w == 0 && h == 0) break;

			static int g[50][50];
			for (int i = 0; i < h; ++i)
			{
				for (int j = 0; j < w; ++j)
				{
					cin >> g[i][j];
				}
			}

			int nextid = 11;
			while (true)
			{
				int begx = -1, begy;
				for (int i = 0; i < h; ++i)
				{
					for (int j = 0; j < w; ++j)
					{
						if (g[i][j] == 1)
						{
							begx = i;
							begy = j;
							i = h;
							break;
						}
					}
				}

				if (begx != -1)
				{
					static vector<tuple<int, int, int>> v;
					v.clear();
					v.push_back({ begx, begy, nextid });
					g[begx][begy] = nextid;
					nextid += 1;

					while (v.size() > 0)
					{
						auto [x, y, id] = v.back();
						v.pop_back();

						for (int i = 0; i < 3; ++i)
						{
							for (int j = 0; j < 3; ++j)
							{
								int nx = x + dx[i];
								int ny = y + dy[j];
								if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
								if (g[nx][ny] != 1) continue;

								g[nx][ny] = id;
								v.push_back({ nx, ny, id });
							}
						}
					}
				}
				else
				{
					cout << nextid - 11 << "\n";
					break;
				}
			}
		}

		return 0;
	}
};