// https://www.acmicpc.net/problem/16953

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p16953
{
	unordered_map<int, int> m;
	int a, b;

	void move(int i, int cnt)
	{
		auto it = m.find(i);
		if (it == m.end())
		{
			m.insert(it, { i, cnt });
		}
		else if (it->second <= cnt)
		{
			return;
		}
		else
		{
			it->second = cnt;
		}

		if (i * 2 <= b)
		{
			move(i * 2, cnt + 1);
		}
		if ((long long)i * 10 + 1 <= b)
		{
			move(i * 10 + 1, cnt + 1);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		cin >> a >> b;
		move(a, 0);

		if (m.find(b) == m.end())
		{
			cout << -1;
		}
		else
		{
			cout << m[b] + 1;
		}

		return 0;
	}
};