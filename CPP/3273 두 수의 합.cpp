// https://www.acmicpc.net/problem/3273

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p3273
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int a[(int)1e6];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		int x;
		cin >> x;

		int cnt[(int)1e6 + 1]{};
		int answer = 0;
		for (int i = 0; i < n; ++i)
		{
			int y = x - a[i];
			if (y <= 1e6)
			{
				answer += cnt[y];
			}
			cnt[a[i]] += 1;
		}

		cout << answer;
		return 0;
	}
};