// https://www.acmicpc.net/problem/6118

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p6118
{
	int main()
	{
		fastio;

		int n, m;
		cin >> n >> m;
		vector<int> e[20001];
		for1(i, m)
		{
			int a, b;
			cin >> a >> b;
			e[a].push_back(b);
			e[b].push_back(a);
		}

		int d[20001]{};
		bool vst[20001]{};
		queue<int> q;
		q.push(1);
		vst[1] = true;
		int maxd = 0;
		while (q.size() > 0)
		{
			int x = q.front();
			q.pop();

			for (int nx : e[x])
			{
				if (vst[nx]) continue;
				vst[nx] = true;
				d[nx] = d[x] + 1;
				maxd = max(maxd, d[nx]);
				q.push(nx);
			}
		}

		int cnt = 0;
		int ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (d[i] == maxd)
			{
				cnt += 1;
				if (ans == 0)
					ans = i;
			}
		}

		cout << ans << " " << maxd << " " << cnt;
		return 0;
	}
};