// https://www.acmicpc.net/problem/9576
// gold1

#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

struct p9576
{
	pair<int, int> r[1001];
	bool nFixed[1001];
	int eLinkTo[1001];

	bool tryLink(int x)
	{
		nFixed[x] = true;

		int s = r[x].first;
		int e = r[x].second + 1;
		for (int i = s; i < e; ++i)
		{
			if (nFixed[eLinkTo[i]]) continue;

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
			int n, m;
			cin >> n >> m;
			for (int i = 0; i < m; ++i)
			{
				int a, b;
				cin >> a >> b;
				r[i] = { a, b };
			}

			memset(eLinkTo, -1, sizeof(int) * m);

			int answer = 0;
			for (int i = 0; i < n; ++i)
			{
				memset(nFixed, false, sizeof(bool) * n);
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

int main()
{
	p9576().main();
}