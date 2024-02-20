//https://www.acmicpc.net/problem/1025

#include <cmath>
#include <iostream>
using namespace std;

void p1025()
{
	// 1. x/y ����
	// 2. i/j delta ��������
	// 3. ���� ���������� Ȯ��
	//
	// ����:
	// ���� �������� ���������� �ʼ���� ������ �߰��� ��� �ȴٴ� ���� ��� ��� Ʋ�Ⱦ���

	int n, m;
	cin >> n >> m;
	char g[9][10] = {};
	for (int i = 0; i < n; ++i)
	{
		cin >> g[i];
	}

	// ���� ū ������ ��ȯ (x/y pos ����)
	auto getMaxSqr = [&](int x, int y) -> int
	{
		// ������ üũ
		int maxSqr = -1;
		auto checkSqr = [&maxSqr](int value)
		{
			if (value > maxSqr)
			{
				double srv = sqrt(value);
				int rcv = (int)round(ceil(srv));

				if (rcv * rcv == value)
				{
					maxSqr = value;
				}
			}
		};

		checkSqr(g[x][y] - '0');

		// ��������
		for (int i = -n + 1; i < n; ++i)
		{
			for (int j = -m + 1; j < m; ++j)
			{
				if (i == 0 && j == 0) continue;

				int nx = x;
				int ny = y;

				int stack = g[nx][ny] - '0';
				while (true)
				{
					nx += i;
					ny += j;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					{
						break;
					}

					stack *= 10;
					stack += g[nx][ny] - '0';
					
					// �߰� Ȯ��
					checkSqr(stack);
				}
			}
		}

		return maxSqr;
	};

	int answer = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int res = getMaxSqr(i,j);
			if (res > answer) answer = res;
		}
	}

	cout << answer << "\n";
}