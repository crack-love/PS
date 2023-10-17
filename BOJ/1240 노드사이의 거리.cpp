// https://www.acmicpc.net/problem/1240

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii pair<int,int>
#define x first
#define y second
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p1240
{
	int main()
	{
		fastio;

		int n, m;
		cin >> n >> m;
		vector<pii> e[1001];
		for1(i, n - 1)
		{
			int a, b, d;
			cin >> a >> b >> d;
			e[a].push_back({ b,d });
			e[b].push_back({ a,d });
		}

		for1(i, m)
		{
			int a, b;
			cin >> a >> b;
			queue<pii> q;
			q.push({ a,0 });
			bool visited[1001]{};
			visited[a] = true;
			while (q.size() > 0)
			{
				auto [p, d] = q.front();
				q.pop();

				if (p == b)
				{
					cout << d << "\n";
					break;
				}

				for (auto [np, dd] : e[p])
				{
					if (visited[np]) continue;
					q.push({ np, d + dd });
					visited[np] = true;
				}
			}
		}

		return 0;
	}
};