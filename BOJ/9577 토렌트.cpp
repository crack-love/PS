// https://www.acmicpc.net/problem/9577
// platinum4

#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <unordered_set>
using namespace std;

struct p9577
{
	unordered_set<int> edge[100];
	bool visit[100];
	int par[100];

	bool tryLink(int x)
	{
		visit[x] = true;

		for (int e : edge[x])
		{
			int p = par[e];
			if (p == -1 || (!visit[p] && tryLink(p)))
			{
				par[e] = x;
				return true;
			}
		}
		return false;
	}

	int main()
	{
		// 이분 매칭
		// 시각마다 받을 수 있는 노드

		int tc;
		cin >> tc;
		while (tc--)
		{
			// init
			for (int i = 0; i < 100; ++i)
			{
				edge[i].clear();
			}

			// get input
			int n, m; // [1 100]
			cin >> n >> m;
			for (int i = 0; i < m; ++i)
			{
				int ts, te, a; // t[0 100], a[0 n]
				cin >> ts >> te >> a;
				for (int j = 0; j < a; ++j)
				{
					int q; // [1 n]
					cin >> q;
					for (int k = ts; k < te; ++k)
					{
						edge[k].insert(q - 1);
					}
				}
			}

			memset(par, -1, sizeof par);

			int answer = -1;
			int linkCnt = 0;
			for (int i = 0; i < 100; ++i)
			{
				memset(visit, 0, sizeof visit);

				if (tryLink(i))
				{
					++linkCnt;
				}

				if (linkCnt >= n)
				{
					answer = i + 1;
					break;
				}
			}

			cout << answer << "\n";
		}
	}
};