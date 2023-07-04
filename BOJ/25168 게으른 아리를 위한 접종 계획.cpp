// https://www.acmicpc.net/problem/27067

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p25168
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		// ������� - ������� ���� ��� ���� ����
		// ��� ��ȿ�Ⱓ - ������� ȿ���Ⱓ, �Ⱓ�� ������ �Ұ� (7��)
		// �ּ� ���Ⱓ - ������� ��Ű� �ּ� ���Ⱓ

		int n, m;
		cin >> n >> m;

		const int SIZE = (int)1e4 + 1;
		vector<pair<int, int>> next[SIZE];
		int pcnt[SIZE]{};
		for1(i, m)
		{
			int s, e, w;
			cin >> s >> e >> w;
			if (w >= 7) w += 1;
			next[s].push_back({ e,w });
			pcnt[e] += 1;
		}

		queue<int> q;
		int day[SIZE]{};
		for (int i = 1; i <= n; ++i)
		{
			if (pcnt[i] == 0)
			{
				q.push(i);
				day[i] = 1;
			}
		}

		while (!q.empty())
		{
			int x = q.front();
			q.pop();

			for (auto [nx, w] : next[x])
			{
				day[nx] = max(day[nx], day[x] + w);

				pcnt[nx] -= 1;
				if (pcnt[nx] == 0)
				{
					q.push(nx);
				}
			}
		}

		cout << *max_element(day, day + n + 1);

		return 0;
	}
};