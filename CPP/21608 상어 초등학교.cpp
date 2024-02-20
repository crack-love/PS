// https://www.acmicpc.net/problem/21608

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p21608
{
	int n;
	int order[400]{};
	bool like[401][401]{};
	int g[20][20]{};
	const int dx[4] = { 0,1,-1,0 };
	const int dy[4] = { 1,0,0,-1 };

	vector<pair<int, int>> find1(int x)
	{
		vector<pair<int, int>> v;
		int maxcnt = 0;

		for2(i, j, n, n)
		{
			if (g[i][j] == 0)
			{
				int cnt = 0;
				for1(k, 4)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					step(nx, ny, n, n);
					int to = g[nx][ny];
					if (like[x][to])
					{
						cnt += 1;
					}
				}
				if (cnt > maxcnt)
				{
					v.clear();
					v.push_back({ i,j });
					maxcnt = cnt;
				}
				else if (cnt == maxcnt)
				{
					v.push_back({ i,j });
				}
			}
		}
		return v;
	}

	vector<pair<int, int>> find2(vector<pair<int, int>> v)
	{
		vector<pair<int, int>> ret;
		int maxcnt = 0;

		for (pair<int, int> p : v)
		{
			int cnt = 0;
			for1(i, 4)
			{
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];
				step(nx, ny, n, n);
				if (g[nx][ny] == 0)
				{
					cnt += 1;
				}
			}
			if (cnt > maxcnt)
			{
				ret.clear();
				ret.push_back(p);
				maxcnt = cnt;
			}
			else if (cnt == maxcnt)
			{
				ret.push_back(p);
			}
		}
		return ret;
	}

	vector<pair<int, int>> find3(vector<pair<int, int>> v)
	{
		sort(v.begin(), v.end());
		return { v[0] };
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n;
		for1(i, n * n)
		{
			int a;
			cin >> a;
			for1(j, 4)
			{
				int b;
				cin >> b;
				like[a][b] = true;
			}
			order[i] = a;
		}

		for1(i, n * n)
		{
			auto v = find1(order[i]);
			if (v.size() > 1)
			{
				v = find2(v);
				if (v.size() > 1)
				{
					v = find3(v);
				}
			}

			g[v[0].first][v[0].second] = order[i];
		}

		int cntToScore[5]{ 0,1,10,100,1000 };
		int answer = 0;
		for2(i, j, n, n)
		{
			int cnt = 0;
			for1(k, 4)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				step(nx, ny, n, n);
				int from = g[i][j];
				int to = g[nx][ny];
				if (like[from][to])
				{
					cnt += 1;
				}
			}

			answer += cntToScore[cnt];
		}

		cout << answer;
		return 0;
	}
};