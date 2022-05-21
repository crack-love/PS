// https://www.acmicpc.net/problem/1047
// platinum5

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 4개의 점으로 이뤄진 모든 직사각형 조합 (n^4)
	// 외부 나무 커트하고 내부 나무 순차로 커트하여 정답 확인
	// 다른 방법: from border position -> stacked height, count (dp)

	int n; // [2 40]
	int x[40] = {};
	int y[40] = {};
	int h[40] = {};
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i] >> h[i];
	}

	// pick four points. it can be duplicated 
	// so it's count range will be 1~4
	int answer = 41;
	for (int p0 = 0; p0 < n; ++p0)
	{
		for (int p1 = p0; p1 < n; ++p1)
		{
			for (int p2 = p1; p2 < n; ++p2)
			{
				for (int p3 = p2; p3 < n; ++p3)
				{
					// calc square border					
					int minX = min({ x[p0], x[p1], x[p2], x[p3] });
					int minY = min({ y[p0], y[p1], y[p2], y[p3] });
					int maxX = max({ x[p0], x[p1], x[p2], x[p3] });
					int maxY = max({ y[p0], y[p1], y[p2], y[p3] });
					int multiX = maxY - minY == 0 ? 1 : 2;
					int multiY = maxX - minX == 0 ? 1 : 2;
					int bSize = (maxX - minX) * multiX + 
								(maxY - minY) * multiY;
					int cutCnt = 0;
					int bGain = 0;

					// cut outside trees
					vector<int> insideHs;
					for (int i = 0; i < n; ++i)
					{
						if (cutCnt >= answer) break;

						if (x[i] < minX || x[i] > maxX ||
							y[i] < minY || y[i] > maxY)
						{
							++cutCnt;
							bGain += h[i];
						}
						else insideHs.push_back(h[i]);
					}

					sort(insideHs.begin(), insideHs.end(), greater<int>());

					// cut inside greedy
					for (int i = 0; i < insideHs.size(); ++i)
					{
						if (bGain >= bSize) break;
						if (cutCnt >= answer) break;

						++cutCnt;
						bGain += insideHs[i];
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