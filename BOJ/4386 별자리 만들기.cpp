// https://www.acmicpc.net/problem/4386

#include <bits/stdc++.h>
using namespace std;

struct p4386
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);	cout.tie(0);

		pair<double, double> ps[100];
		vector<tuple<double, int, int>> dis;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			double a, b;
			cin >> a >> b;
			ps[i] = { a, b };

			for (int j = 0; j < i; ++j)
			{
				double xx = (ps[i].first - ps[j].first);
				double yy = (ps[i].second - ps[j].second);
				double d = sqrt(xx * xx + yy * yy);
				dis.push_back({ d, i, j });
			}
		}

		sort(dis.begin(), dis.end());

		int par[100];
		memset(par, -1, sizeof(par));

		auto find = [&par](int x, auto& self) -> int
		{
			return par[x] == -1 ? x : (par[x] = self(par[x], self));
		};

		double answer = 0;
		for (int i = 0; i < dis.size(); ++i)
		{
			auto [d, a, b] = dis[i];
			int pa = find(a, find);
			int pb = find(b, find);
			if (pa != pb)
			{
				par[pa] = pb;
				answer += d;
			}
		}

		cout.setf(ios::fixed);
		cout.precision(2);
		cout << answer;
		return 0;
	}
};