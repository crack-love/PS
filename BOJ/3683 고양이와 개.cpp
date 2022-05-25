// https://www.acmicpc.net/problem/3683
// platinum3

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

struct p3683
{
	vector<int> catLovers;
	vector<int> dogLovers;
	vector<int> edge[501]; // clover to dlover
	bool visited[501];
	int par[501];

	int getInput()
	{
		static int like[501];
		static int dislike[501];
		static string b0, b1;

		// init
		catLovers.clear();
		dogLovers.clear();
		for (int i = 0; i < 501; ++i)
			edge[i].clear();

		// get input
		int c, d, v; // cd[1 100], v[0 500]
		cin >> c >> d >> v;
		for (int i = 1; i <= v; ++i)
		{
			char t0, t1;
			int n0, n1;
			cin >> t0 >> b0 >> t1 >> b1;
			n0 = stoi(b0);
			n1 = stoi(b1);

			if (t0 == 'C')
			{
				catLovers.push_back(i);
				n1 += 100;
			}
			else
			{
				dogLovers.push_back(i);
				n0 += 100;
			}

			like[i] = n0;
			dislike[i] = n1;
		}

		// set edge
		for (int i = 0; i < catLovers.size(); ++i)
		{
			for (int j = 0; j < dogLovers.size(); ++j)
			{
				int ci = catLovers[i];
				int di = dogLovers[j];

				if (like[ci] == dislike[di] ||
					like[di] == dislike[ci])
				{
					edge[ci].push_back(di);
				}
			}
		}

		return v;
	}

	bool tryLink(int x)
	{
		visited[x] = true;
		for (int e : edge[x])
		{
			int p = par[e];
			if (p == -1 || (!visited[p] && tryLink(p)))
			{
				par[e] = x;
				return true;
			}
		}
		return false;
	}

	int bipariteMatching()
	{
		int ans = 0;
		memset(par, -1, sizeof par);
		for (int i = 0; i < catLovers.size(); ++i)
		{
			memset(visited, 0, sizeof visited);

			int ci = catLovers[i];
			if (tryLink(ci))
			{
				++ans;
			}
		}
		return ans;
	}

	void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int v = 0;
		int t;
		cin >> t;
		while (t--)
		{
			v = getInput();

			int mvc = bipariteMatching();

			cout << v - mvc << "\n";
		}
	}
};