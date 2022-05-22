// https://www.acmicpc.net/problem/11375
// platinum4

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> edges[1001];
bool nFixed[1001];
int eLink[1001];

// O(m)
bool link(int x)
{
	if (nFixed[x]) return false;
	nFixed[x] = true;

	for (int e : edges[x])
	{
		if (eLink[e] == -1 || link(eLink[e]))
		{
			eLink[e] = x;
			return true;
		}
	}

	return false;
}

int p11375()
{
	// ÀÌºÐ¸ÅÄª

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int c, w;
		cin >> c;
		while (c--)
		{
			cin >> w;
			edges[i].push_back(w);
		}
	}

	memset(eLink, -1, sizeof(eLink));

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		memset(nFixed, false, sizeof(nFixed));

		if (link(i))
		{
			++answer;
		}
	}

	cout << answer;
	return 0;
}