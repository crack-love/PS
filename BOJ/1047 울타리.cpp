// https://www.acmicpc.net/problem/1047
// platinum5

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 두개의 점으로 이뤄진 모든 직사각형 조합 (n^2)
	// 외부 나무 커트하고 내부 나무 순차로 커트하여 정답 확인

	int n; // [2 40]
	int x[40] = {};
	int y[40] = {};
	int h[40] = {};
	vector<int> originTrees;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i] >> h[i];
		originTrees.push_back(i);
	}

	int answer = 41;
	for (int p0 = 0; p0 < n; ++p0)
	{
		vector<int> pvec; // point trees
		pvec.push_back(p0);
		for (int p1 = 0; p1 < n; ++p1)
		{
			if (find(pvec.begin(), pvec.end(), p1) != pvec.end()) continue;
			pvec.push_back(p1);
			for (int p2 = 0; p2 < n; ++p2)
			{
				if (find(pvec.begin(), pvec.end(), p2) != pvec.end()) continue;
				pvec.push_back(p2);
				for (int p3 = 0; p3 < n; ++p3)
				{
					if (find(pvec.begin(), pvec.end(), p3) != pvec.end()) continue;
					pvec.push_back(p3);

					// inside trees
					vector<int> invec = originTrees;

					// calc square border					
					int minX = min({ x[p0], x[p1], x[p2], x[p3] });
					int minY = min({ y[p0], y[p1], y[p2], y[p3] });
					int maxX = max({ x[p0], x[p1], x[p2], x[p3] });
					int maxY = max({ y[p0], y[p1], y[p2], y[p3] });
					int multiX = maxY - minY == 0 ? 1 : 2;
					int multiY = maxX - minX == 0 ? 1 : 2;
					int bSize = (maxX - minX) * multiX + (maxY - minY) * multiY;
					int cutCnt = 0;
					int bGain = 0;

					// cut over line trees
					for (int i = 0; i < invec.size(); ++i)
					{
						int ti = invec[i];
						if (x[ti] < minX || x[ti] > maxX ||
							y[ti] < minY || y[ti] > maxY)
						{
							++cutCnt;
							bGain += h[ti];
							invec.erase(invec.begin() + i);
						}
						
						if (bGain >= bSize) break;
					}

					// cut inside greedy
					while (bGain < bSize && invec.size() > 0)
					{
						int maxi = 0;
						for (int i = 0; i < invec.size(); ++i)
						{
							int ti = invec[i];
							if (h[ti] > h[invec[maxi]])
							{
								maxi = i;
							}
						}

						++cutCnt;
						bGain += h[invec[maxi]];
						invec.erase(invec.begin() + maxi);
					}

					if (bGain >= bSize && cutCnt < answer)
					{
						answer = cutCnt;
					}
				}
			}
		}
	}

	cout << answer;
	return 0;
}