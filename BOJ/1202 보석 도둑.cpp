// https://www.acmicpc.net/problem/1202

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p1202
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, k;
		cin >> n >> k;

		const int MAX = (int)3e5;
		pair<int, int> gems[MAX];
		int bags[MAX];

		for1(i, n)
		{
			cin >> gems[i].first >> gems[i].second;
		}
		for1(i, k)
		{
			cin >> bags[i];
		}
		sort(gems, gems + n);
		sort(bags, bags + k);

		priority_queue<int> gcandi;
		int gidx = 0;
		long long ans = 0;
		for1(bidx, k)
		{
			while (gidx < n && gems[gidx].first <= bags[bidx])
			{
				gcandi.push(gems[gidx++].second);
			}

			if (gcandi.size() > 0)
			{
				ans += gcandi.top();
				gcandi.pop();
			}
		}

		cout << ans;
		return 0;
	}
};