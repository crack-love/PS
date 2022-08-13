// https://www.acmicpc.net/problem/1647

#include <bits/stdc++.h>
using namespace std;

struct p1647
{
	static const int MAX_N = (int)1e5;
	static const int MAX_M = (int)1e6;
	typedef tuple<int, int, int> tp;
	tp e[MAX_M];
	int p[MAX_N + 1]{};

	int find(int x)
	{
		return p[x] == x ? x : (p[x] = find(p[x]));
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			e[i] = { a, b, c };
		}

		for (int i = 1; i <= n; ++i)
		{
			p[i] = i;
		}

		sort(e, e + m, [](tp& a, tp& b)
			{
				return get<2>(a) < get<2>(b);
			});

		int ecnt = 0;
		int answer = 0;
		for (int i = 0; i < m && ecnt < n - 2; ++i)
		{
			auto& [a, b, c] = e[i];
			int pa = find(a);
			int pb = find(b);
			if (pa != pb)
			{
				p[pa] = pb;
				answer += c;
				ecnt += 1;
			}
		}

		cout << answer;
		return 0;
	}
};