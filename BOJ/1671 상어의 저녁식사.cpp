// https://www.acmicpc.net/problem/1671
// platinum3

#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> edges[50];
bool visited[50];
int linkFrom[50];

bool tryLink(int x)
{
	visited[x] = true;

	for (int e : edges[x])
	{
		int ex = linkFrom[e];
		if (ex != -1)
		{
			if (visited[ex]) continue;
			if (!tryLink(ex)) continue;
		}

		linkFrom[e] = x;
		return true;
	}

	return false;
}

int main()
{
	// 이분매칭 (2번)
	// 어떤 상어를 잡아먹은 상어는 잡아먹힐 수 있다
	// 상어는 서로 잡아먹을 수 없다

	int n;
	cin >> n;
	int a[50], b[50], c[50];
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i] >> c[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i == j) continue;
			if (a[i] >= a[j] && b[i] >= b[j] && c[i] >= c[j])
			{
				if (a[i] == a[j] && b[i] == b[j] && c[i] == c[j])
				{
					if (i < j)
						edges[i].push_back(j);
				}
				else
				{
					edges[i].push_back(j);
				}
			}
		}

	memset(linkFrom, -1, sizeof(linkFrom));

	int answer = n;
	for (int i = 0; i < n * 2; ++i)
	{
		memset(visited, 0, sizeof(visited));

		if (tryLink(i / 2))
			--answer;
	}

	cout << answer;
	return 0;
}