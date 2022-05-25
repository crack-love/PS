// https://www.acmicpc.net/problem/17481
// platinum4

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct p17481
{
	vector<int> edge[1000];
	bool visited[1000];
	int par[1000];
	int tryLink(int x)
	{
		visited[x] = true;
		for (int e : edge[x])
		{
			int p = par[e];
			if (p == -1 || (!visited[p] && tryLink(p)))
			{
				par[e] = x;
				return 1;
			}
		}
		return 0;
	}

	unordered_map<string, int> ntoi;
	int nextid = 0;
	int getNameIndex(string& name)
	{
		auto it = ntoi.find(name);
		if (it == ntoi.end())
		{
			ntoi.insert({ name, nextid });
			return nextid++;
		}
		else return it->second;
	}

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		int n, m; // [2 1000]
		cin >> n >> m;
		string buff;
		for (int i = 0; i < m; ++i)
		{
			cin >> buff;
			getNameIndex(buff);
		}

		for (int i = 0; i < n; ++i)
		{
			int k;
			cin >> k;
			for (int j = 0; j < k; ++j)
			{
				cin >> buff;
				int idx = getNameIndex(buff);
				edge[i].push_back(idx);
			}
		}

		memset(par, -1, sizeof(int) * m);

		int linked = 0;
		for (int i = 0; i < n; ++i)
		{
			memset(visited, false, sizeof(bool) * n);
			if (tryLink(i))
			{
				++linked;
			}
		}

		if (linked >= n)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO\n";
			cout << linked;
		}
	}
};