// https://www.acmicpc.net/problem/15649

#include <iostream>
using namespace std;

struct p15649
{
	int n, m;
	int arr[8];

	void printseq(int i, int visit)
	{
		if (i == m)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << arr[j] << " ";
			}
			cout << "\n";
			return;
		}

		for (int j = 1; j <= n; ++j)
		{
			if (visit & (1 << j)) continue;

			int nvisit = visit | (1 << j);
			arr[i] = j;
			printseq(i + 1, nvisit);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cout.tie(0);

		cin >> n >> m;
		printseq(0, 0);
	}
};