// https://www.acmicpc.net/problem/11376
// platinum4

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct p11376
{
	vector<int> nEdges[1001];
	int wLinkTo[1001];
	bool visit[1001];

	bool tryLink(int x)
	{
		visit[x] = true;

		for (int w : nEdges[x])
		{
			int px = wLinkTo[w];
			if (px != -1)
			{
				if (px == x) continue;
				if (visit[px]) continue;
				if (!tryLink(px)) continue;
			}

			wLinkTo[w] = x;
			return true;
		}

		return false;
	}

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			int c;
			cin >> c;
			while (c--)
			{
				int w;
				cin >> w;
				nEdges[i].push_back(w);
			}
		}

		memset(wLinkTo, -1, sizeof(int) * (m + 1));

		int answer = 0;
		for (int i = 0; i < n * 2; ++i)
		{
			if (i % 1 == 0)
			{
				memset(visit, 0, sizeof(bool) * (n + 1));
			}

			if (tryLink(i / 2 + 1))
			{
				++answer;
			}
		}

		cout << answer;
		return 0;
	}
};
