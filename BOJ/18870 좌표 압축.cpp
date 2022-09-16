// https://www.acmicpc.net/problem/18870

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
using namespace std;

struct p18870
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		pair<int, int> arr[(int)1e6];
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			arr[i] = { x, i };
		}

		sort(arr, arr + n);

		int ans[(int)1e6];
		int lastValue = arr[0].first;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (arr[i].first > lastValue)
			{
				cnt += 1;
				lastValue = arr[i].first;
			}

			ans[arr[i].second] = cnt;
		}

		for (int i = 0; i < n; ++i)
		{
			cout << ans[i] << " ";
		}

		return 0;
	}
};