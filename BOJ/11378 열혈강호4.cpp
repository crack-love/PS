// https://www.acmicpc.net/problem/11378
// platinum3

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct p11378
{
	vector<int> edges[1001];
	bool visited[1001];
	int eLinked[1001];

	// O(NM)
	bool tryLink(int x)
	{
		visited[x] = true;

		for (int e : edges[x])
		{
			int ex = eLinked[e];
			if (ex != -1)
			{
				if (visited[ex]) continue;
				if (!tryLink(ex)) continue;
			}

			eLinked[e] = x;
			return true;
		}
		return false;
	}

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		// get input
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; ++i)
		{
			int wc;
			cin >> wc;
			while (wc--)
			{
				int w;
				cin >> w;
				edges[i].push_back(w);
			}
		}

		memset(eLinked, -1, sizeof(int) * (m + 1));

		// n
		// n -> people -> work -> sink
		int answer = 0;
		for (int i = 1; i <= n; ++i)
		{
			memset(visited, 0, sizeof(visited));

			if (tryLink(i))
			{
				++answer;
			}
		}

		// k
		// k -> people -> work -> sink
		while (k)
		{
			bool bLinked = false;

			for (int i = 1; i <= n; ++i)
			{
				memset(visited, 0, sizeof(visited));

				if (tryLink(i))
				{
					--k;
					bLinked = true;
					++answer;
					break;
				}
			}

			if (!bLinked)
			{
				break;
			}
		}

		cout << answer;
		return 0;
	}
}