// https://www.acmicpc.net/problem/15654

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p15654
{
	int n, m;
	int arr[8];
	vector<int> selected;

	void select(int bit)
	{
		if (selected.size() >= m)
		{
			for (int i : selected)
			{
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				if (!(bit & (1 << i)))
				{
					selected.push_back(i);
					select(bit | (1 << i));
					selected.pop_back();
				}
			}
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		sort(arr, arr + n);
		select(0);

		return 0;
	}
};