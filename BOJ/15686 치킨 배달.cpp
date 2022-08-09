// https://www.acmicpc.net/problem/15686

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct p15686
{
	int n, m;
	int houseSize = 0;
	int storeSize = 0;
	pair<int, int> housePos[100];
	pair<int, int> storePos[13];
	int dis[100][13];

	int getCityValue(int idx, vector<int>& store)
	{
		if (idx == storeSize)
		{
			int distSum = 0;
			for (int i = 0; i < houseSize; ++i)
			{
				int minDist = 101;
				for (int j = 0; j < store.size(); ++j)
				{
					minDist = min(minDist, dis[i][store[j]]);
				}
				distSum += minDist;
			}
			return distSum;
		}

		int v0 = (int)1e9;
		if (store.size() < m)
		{
			store.push_back(idx);
			v0 = getCityValue(idx + 1, store);
			store.pop_back();
		}

		int v1 = getCityValue(idx + 1, store);

		return min(v0, v1);
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int x;
				cin >> x;
				if (x == 1)
				{
					housePos[houseSize++] = { i, j };
				}
				else if (x == 2)
				{
					storePos[storeSize++] = { i, j };
				}
			}
		}

		// get distance from house to each target
		for (int i = 0; i < houseSize; ++i)
		{
			for (int j = 0; j < storeSize; ++j)
			{
				dis[i][j] =
					abs(housePos[i].first - storePos[j].first) +
					abs(housePos[i].second - storePos[j].second);
			}
		}

		vector<int> s;
		cout << getCityValue(0, s);
		return 0;
	}
};