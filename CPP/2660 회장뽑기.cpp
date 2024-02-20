// https://www.acmicpc.net/problem/2660

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define max(a,b) (a > b ? a : b)

struct p2660
{
	int main()
	{
		int e[51][51] = {};

		int n;
		cin >> n;
		while (true)
		{
			int a, b; // [1 50]
			cin >> a >> b;
			if (a == -1 && b == -1)
			{
				break;
			}

			e[a][b] = e[b][a] = 1;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				for (int k = j + 1; k <= n; ++k)
				{
					if (e[j][i] > 0 && e[i][k] > 0)
					{
						int nv = e[j][i] + e[i][k];
						if (nv < e[j][k] || e[j][k] == 0)
						{
							e[j][k] = e[k][j] = nv;
						}
					}
				}
			}
		}

		int minScore = 51;
		int score[51] = {};
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				score[i] = max(score[i], e[i][j]);
			}

			minScore = min(minScore, score[i]);
		}

		vector<int> answer;
		if (minScore != 0)
		{
			for (int i = 1; i <= n; ++i)
			{
				if (score[i] == minScore)
				{
					answer.push_back(i);
				}
			}
		}

		sort(answer.begin(), answer.end());
		cout << minScore << " " << answer.size() << "\n";
		for (int i = 0; i < answer.size(); ++i)
		{
			cout << answer[i] << " ";
		}

		return 0;
	}
};