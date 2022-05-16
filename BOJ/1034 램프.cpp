// https://www.acmicpc.net/problem/1034

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void p1034()
{
	// �ϳ��� �� ����
	// �ش� ��� ���� ����� ���� ������ ����++
	// �ش� ���� k�� ������ �����ؾ��� (Ȧ¦)

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	string g[50];
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> g[i];
	}
	cin >> k;

	bool visit[50] = {};
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		if (visit[i]) continue;
		visit[i] = true;

		int zcnt = count(g[i].begin(), g[i].end(), '0');
		int rcnt = 0;

		if (zcnt % 2 == k % 2 && zcnt <= k)
		{
			rcnt = 1;

			for (int j = i + 1; j < n; ++j)
			{
				if (g[i] == g[j])
				{
					visit[j] = true;
					++rcnt;
				}
			}
		}

		if (rcnt > answer) 
			answer = rcnt;
	}

	cout << answer << "\n";
}

int main()
{
	p1034();
	return 0;
}