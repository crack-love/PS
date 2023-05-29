// https://www.acmicpc.net/problem/11000

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dd[2][4] = { {0,0,1,-1}, { 1,-1,0,0 } };
using namespace std;

struct p11000
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		pair<int, int> a[200000];
		int n;
		cin >> n;
		for1(i, n)
		{
			int s, e;
			cin >> s >> e;
			a[i] = { s,e };
		}

		sort(a, a + n);

		int ans = 0;
		int cnt = 0;
		priority_queue<int, vector<int>, greater<int>> eq;
		for1(i, n)
		{
			if (eq.empty())
			{
				cnt += 1;
				eq.push(a[i].second);
			}
			else
			{
				if (eq.top() <= a[i].first)
				{
					eq.pop();
					eq.push(a[i].second);
				}
				else
				{
					cnt += 1;
					eq.push(a[i].second);
				}
			}

			ans = max(cnt, ans);
		}

		cout << ans;

		return 0;
	}
};