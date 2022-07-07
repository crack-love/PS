// https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>
using namespace std;

struct p2164
{
	int main()
	{
		deque<int> q;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			q.push_back(i + 1);
		}

		int last = 0;
		while (!q.empty())
		{
			if (!q.empty())
			{
				last = q.front();
				q.pop_front();
			}

			if (!q.empty())
			{
				last = q.front();
				q.push_back(q.front());
				q.pop_front();
			}
		}

		cout << last;
		return 0;
	}
};