// https://www.acmicpc.net/problem/9019
// gold4

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

struct p9019
{
	queue<pair<int, string>> q;
	string order;
	int a, b;
	bool visited[10000];

	bool MoveNext(char c, int x)
	{
		if (visited[x]) return 1;
		visited[x] = 1;

		order.push_back(c);
		if (x == b)
		{
			cout << order << "\n";
			return 0;
		}
		q.push({ x, order });
		order.pop_back();
		return 1;
	}

	int main()
	{
		int t;
		cin >> t;
		while (t--)
		{
			cin >> a >> b;

			memset(visited, 0, sizeof visited);
			while (!q.empty())
				q.pop();

			q.push({ a, "" });
			visited[a] = 1;

			while (!q.empty())
			{
				int x = q.front().first;
				order = q.front().second;
				q.pop();

				// d
				int x0 = (x * 2) % 10000;
				if (!MoveNext('D', x0)) break;

				// s
				int x1 = (x + -1 + 10000) % 10000;
				if (!MoveNext('S', x1)) break;

				// l
				int x2 = (x * 10 + x / 1000) % 10000;
				if (!MoveNext('L', x2)) break;

				// r
				int x3 = x / 10 + (x % 10 * 1000);
				if (!MoveNext('R', x3)) break;
			}
		}

		return 0;
	}
};