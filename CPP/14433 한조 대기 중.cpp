// https://www.acmicpc.net/problem/14433
// platinum4

#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

struct p14433
{
	unordered_set<int> e1[301];
	unordered_set<int> e2[301];
	bool visited[301];
	int par[301];

	bool tryLink(int x, unordered_set<int> edge[])
	{
		visited[x] = true;
		for (int e : edge[x])
		{
			int p = par[e];
			if (p == -1 || (!visited[p] && tryLink(p, edge)))
			{
				par[e] = x;
				return true;
			}
		}
		return false;
	}

	int bipariteMatching(int n, unordered_set<int> edge[])
	{
		int ans = 0;
		memset(par, -1, sizeof par);
		for (int i = 1; i <= n; ++i)
		{
			memset(visited, 0, sizeof visited);

			if (tryLink(i, edge))
			{
				++ans;
			}
		}
		return ans;
	}

	int main()
	{
		// get input
		// nm[1 300], k1k2[1 500]
		int n, m, k1, k2;
		cin >> n >> m >> k1 >> k2;
		for (int i = 0; i < k1 + k2; ++i)
		{
			int a, b;
			cin >> a >> b;
			if (i < k1) 
				e1[a].insert(b);
			else 
				e2[a].insert(b);
		}

		int pickCnt1 = bipariteMatching(n, e1);
		int pickCnt2 = bipariteMatching(n, e2);

		cout << ((pickCnt1 >= pickCnt2) ? "그만 알아보자" : "네 다음 힐딱이");
		return 0;
	}
};