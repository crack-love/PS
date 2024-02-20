// https://www.acmicpc.net/problem/2570
// platinum2

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>
using namespace std;

// ÀÌºÐ ¸ÅÄª (ÃÖ´ë ¸ÅÄª)

struct p2570
{
	unordered_set<int> edgeV0[8000];
	int visited[8000];
	int par[8000];

	bool tryLink(int x)
	{
		visited[x] = true;

		for (int v1 : edgeV0[x])
		{
			int p = par[v1];
			if (p == -1 || (!visited[p] && tryLink(p)))
			{
				par[v1] = x;
				return true;
			}
		}
		return false;
	}

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int gridBlock[101][101] = {};
		int n, m; // n[1 100], m[0 10000]
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int x, y;
			cin >> x >> y;
			gridBlock[x][y] = 1;
		}

		// init vertex
		// v0/v1 index starts from one
		int gridV0[101][101] = {};
		int gridV1[101][101] = {};
		int v0Cnt = 0;
		int v1Cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (gridBlock[i][j]) continue;

				if (gridV0[i][j] == 0)
				{
					int nx = i;
					int ny = j;
					v0Cnt += 1;
					while (nx <= n && ny <= n)
					{
						if (gridBlock[nx][ny]) break;
						gridV0[nx++][ny++] = v0Cnt;
					}
				}

				if (gridV1[i][j] == 0)
				{
					int nx = i;
					int ny = j;
					v1Cnt += 1;
					while (nx <= n && ny >= 1)
					{
						if (gridBlock[nx][ny]) break;
						gridV1[nx++][ny--] = v1Cnt;
					}
				}
			}
		}

		// init edge
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (gridBlock[i][j]) continue;
				int v0 = gridV0[i][j];
				int v1 = gridV1[i][j];
				edgeV0[v0].insert(v1);
			}
		}

		// bipariteMatching
		int matchCnt = 0;
		memset(par, -1, sizeof par);
		for (int i = 1; i <= v0Cnt; ++i)
		{
			memset(visited, 0, sizeof visited);

			if (tryLink(i))
			{
				matchCnt += 1;
			}
		}

		cout << matchCnt;

		return 0;
	}
};