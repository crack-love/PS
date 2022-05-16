// https://www.acmicpc.net/problem/1027
// gold4

#include <iostream>
using namespace std;

int p1027()
{
	// 빌딩 ij 선분 (50*50)
	// 해당 선분에 k빌딩이 닿는가 (*50)

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int g[50] = {};
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> g[i];
	}

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i == j) continue;

			// y = mx + c
			double m = ((double)g[j]-g[i])/((double)j-i);
			double c = g[i] - (m*i);
			bool blocked = false;
			int delta = i > j ? -1 : 1;

			for (int k = i + delta; k != j; k += delta)
			{
				// check k is higher than i to j line
				double lineHeight = m * k + c;
				if (lineHeight <= g[k])
				{
					blocked = true;
					break;
				}
			}

			if (!blocked)
				++cnt;
		}

		if (cnt > answer)
			answer = cnt;
	}

	cout << answer << "\n";
	return 0;
}

// 다른 방법
// 1. ccw로 풀 수 있다고 한다. ccw는 처음 들어본다.
// 1. 기울기를 비교하여 확인할 수 있다. (https://www.acmicpc.net/source/43401688)