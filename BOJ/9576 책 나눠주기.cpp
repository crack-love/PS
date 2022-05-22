// https://www.acmicpc.net/problem/9576
// gold1

#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

struct p9576
{
	pair<int, int> range[1001];
	bool mFixed[1001];
	int eLinkTo[1001];

	bool tryLink(int x)
	{
		if (mFixed[x]) return false;
		mFixed[x] = true;

		int s = range[x].first;
		int e = range[x].second + 1;
		for (int i = s; i < e; ++i)
		{
			if (eLinkTo[i] == -1 || tryLink(eLinkTo[i]))
			{
				eLinkTo[i] = x;
				return true;
			}
		}

		return false;
	};

	int main()
	{
		int t;
		cin >> t;
		while (t--)
		{
			memset(range, 0, sizeof(range));
			memset(mFixed, 0, sizeof(mFixed));
			memset(eLinkTo, -1, sizeof(eLinkTo));

			int n, m; // [1 1000]
			cin >> n >> m;
			for (int i = 1; i <= m; ++i)
			{
				int a, b; // [1 n]
				cin >> a >> b;
				range[i] = { a, b };
			}

			int answer = 0;
			for (int i = 1; i <= m; ++i)
			{
				memset(mFixed, false, sizeof(mFixed));

				if (tryLink(i))
				{
					++answer;
				}
			}

			cout << answer << "\n";
		}

		return 0;
	}
};