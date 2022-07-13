// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	const int MAX = 200001;
	bool visit[MAX] = {};
	deque<pair<int, int>> q;

	q.push_back({n, 0});
	visit[n] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int c = q.front().second; q.pop_front();

		if (x == k)
		{
			cout << c;
		}

		if (x * 2 < MAX && !visit[x * 2])
		{
			visit[x * 2] = true;
			q.push_front({x * 2,  c});
		}

		if (x - 1 >= 0 && !visit[x - 1])
		{
			visit[x - 1] = true;
			q.push_back({x - 1, c + 1});
		}

		if (x + 1 < MAX && !visit[x + 1])
		{
			visit[x + 1] = true;
			q.push_back({x + 1, c + 1});
		}
	}

	return 0;
}