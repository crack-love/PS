// https://www.acmicpc.net/problem/11406
// platinum4

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct p11406
{
	// src -> people -> store -> sink

	int pSize, sSize;
	int sUse[100] = {};
	int sCap[100] = {};
	bool visited[100];
	int c[100][100] = {}; // people, stroe
	int f[100][100] = {};
	vector<int> sToP[100];
	vector<int> pToS[100];

	bool tryLink(int x)
	{
		visited[x] = true;

		for (int si : pToS[x])
		{
			if (f[x][si] >= c[x][si]) continue;

			bool hasSpace = true;
			if (sUse[si] >= sCap[si])
			{
				hasSpace = false;
				for (int pi : sToP[si])
				{
					if (visited[pi]) continue;
					if (f[pi][si] > 0)
					{
						if (tryLink(pi))
						{
							hasSpace = true;
							sUse[si] -= 1;
							f[pi][si] -= 1;
							break;
						}
					}
				}
			}

			if (hasSpace)
			{
				sUse[si] += 1;
				f[x][si] += 1;
				return true;
			}
		}
		return false;
	}

	int main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);

		// get input
		int want[100] = {};
		cin >> pSize >> sSize;
		for (int i = 0; i < pSize; ++i)
		{
			cin >> want[i];
		}
		for (int i = 0; i < sSize; ++i)
		{
			cin >> sCap[i];
		}
		for (int i = 0; i < sSize; ++i)
		{
			for (int j = 0; j < pSize; ++j)
			{
				cin >> c[j][i];

				if (c[j][i] > 0)
				{
					sToP[i].push_back(j);
					pToS[j].push_back(i);
				}
			}
		}

		int answer = 0;
		for (int i = 0; i < pSize; ++i)
		{
			for (int j = 0; j < want[i]; ++j)
			{
				memset(visited, 0, sizeof visited);

				if (tryLink(i))
				{
					++answer;
				}
			}
		}

		cout << answer;
		return 0;
	}
};