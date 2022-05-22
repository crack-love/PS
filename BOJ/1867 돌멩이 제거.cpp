// https://www.acmicpc.net/problem/1867
// platinum3

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int p1867()
{
	// 최대 이분 매칭

	int n, k;
	cin >> n >> k;
	vector<int> xHas[501];
	for (int i = 0; i < k; ++i)
	{
		int x, y;
		cin >> x >> y;
		xHas[x].push_back(y);
	}

	bool xVisit[501] = {};
	int yLinkTo[501] = {};
	memset(yLinkTo, -1, sizeof(yLinkTo));

	auto tryLink = [&xVisit, &yLinkTo, &xHas](int x, auto& tryLink) -> bool
	{
		xVisit[x] = true;

		for (int y : xHas[x])
		{	
			int yx = yLinkTo[y];

			if (yx != -1)
			{
				if (xVisit[yx]) continue;
				if (!tryLink(yx, tryLink)) continue;
			}
			
			yLinkTo[y] = x;

			return true;
		}

		return false;
	};

	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		memset(xVisit, 0, sizeof(xVisit));

		if (tryLink(i, tryLink))
		{
			answer += 1;
		}
	}

	cout << answer;
	return 0;
}