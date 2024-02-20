// https://www.acmicpc.net/problem/14248

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p14248
{
	int main()
	{
		fastio;

		int n;
		cin >> n;
		int a[100000];
		for1(i, n)
		{
			cin >> a[i];
		}
		int s;
		cin >> s;
		s -= 1;

		stack<int> st;
		vector<bool> visited(n, false);
		st.push(s);
		visited[s] = true;
		int ans = 0;
		while (st.size() > 0)
		{
			int t = st.top();
			st.pop();
			ans += 1;

			int p = t - a[t];
			if (p >= 0 && !visited[p])
			{
				st.push(p);
				visited[p] = true;

			}
			p = t + a[t];
			if (p < n && !visited[p])
			{
				st.push(p);
				visited[p] = true;
			}
		}

		cout << ans;
		return 0;
	}
};