// https://www.acmicpc.net/problem/9466

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p9466
{
	int n;
	int to[100001]{};
	int visited[100001]{};
	int answer = 0;

	void dfs(int x, int g, stack<int>& history)
	{
		if (visited[x] == g)
		{
			int cnt = 1;
			while (!history.empty())
			{
				int t = history.top();
				history.pop();
				if (t == x)
				{
					answer -= cnt;
					break;
				}
				else
				{
					cnt += 1;
				}
			}
		}
		else if (visited[x] == 0)
		{
			visited[x] = g;
			history.push(x);

			dfs(to[x], g, history);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			for (int i = 1; i <= n; ++i)
			{
				cin >> to[i];
			}

			fill(visited, visited + n + 1, 0);
			answer = n;
			int nextGroup = 1;

			for (int i = 1; i <= n; ++i)
			{
				stack<int> history;
				dfs(i, nextGroup++, history);
			}
			cout << answer << "\n";
		}
		return 0;
	}
};