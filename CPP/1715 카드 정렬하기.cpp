// https://www.acmicpc.net/problem/1715

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1715
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		priority_queue<int, vector<int>, greater<int>> pq;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			pq.push(x);
		}

		long long ans = 0;
		while (!pq.empty())
		{
			int x = pq.top(); pq.pop();
			if (!pq.empty())
			{
				int y = pq.top(); pq.pop();
				pq.push(x + y);
				ans += x + y;
			}
		}
		cout << ans;

		return 0;
	}
};