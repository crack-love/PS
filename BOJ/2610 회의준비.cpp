// https://www.acmicpc.net/problem/2610
// glod2

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct p2610
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		int e[101][101] = {};
		int n, m;
		cin >> n >> m;
		while (m--)
		{
			int a, b;
			cin >> a >> b;
			e[a][b] = 1;
			e[b][a] = 1;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (e[i][j] == 0) continue;
				for (int k = j + 1; k <= n; ++k)
				{
					if (e[i][k] == 0) continue;

					if (e[j][k] == 0 || e[j][i] + e[i][k] < e[j][k])
					{
						e[j][k] = e[k][j] = e[j][i] + e[i][k];
					}
				}
			}
		}

		int visited[101] = {};
		vector<int> answer;
		vector<int> elements;
		queue<int> q;

		while (true)
		{
			// find new group
			elements.clear();
			for (int i = 1; i <= n; ++i)
			{
				if (!visited[i])
				{
					visited[i] = true;
					q.push(i);
					elements.push_back(i);
					break;
				}
			}

			if (q.empty())
			{
				break;
			}

			// search
			while (!q.empty())
			{
				int x = q.front();
				q.pop();

				for (int i = 1; i <= n; ++i)
				{
					if (e[x][i] && !visited[i])
					{
						visited[i] = true;
						q.push(i);
						elements.push_back(i);
					}
				}
			}

			// find centest one
			int minIdx = 0;
			int minDist = 101;
			for (int i : elements)
			{
				int maxDist = 0;
				for (int j = 1; j <= n; ++j)
				{
					if (e[i][j] > maxDist)
					{
						maxDist = e[i][j];
					}
				}

				if (maxDist < minDist)
				{
					minIdx = i;
					minDist = maxDist;
				}
			}

			answer.push_back(minIdx);
		}

		// print answer
		sort(answer.begin(), answer.end());
		cout << answer.size() << "\n";
		for (int i : answer)
		{
			cout << i << "\n";
		}

		return 0;
	}
};

int main()
{
	p2610().main();
}