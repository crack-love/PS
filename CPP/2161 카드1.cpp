// https://www.acmicpc.net/problem/2161

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2161
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;

		deque<int> q;
		for (int i = 0; i < n; ++i)
		{
			q.push_back(i + 1);
		}

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop_front();

			if (!q.empty())
			{
				q.push_back(q.front());
				q.pop_front();
			}
		}

		return 0;
	}
};