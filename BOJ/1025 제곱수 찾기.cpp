//https://www.acmicpc.net/problem/1025

#include <cmath>
#include <iostream>
using namespace std;

void p1025()
{
	// 1. x/y 시작
	// 2. i/j delta 등차수열
	// 3. 값이 제곱수인지 확인
	//
	// 착오:
	// 문제 지문에서 등차수열이 필수라고 했지만 중간에 끊어도 된다는 말이 없어서 계속 틀렸었음

	int n, m;
	cin >> n >> m;
	char g[9][10] = {};
	for (int i = 0; i < n; ++i)
	{
		cin >> g[i];
	}

	// 가장 큰 제곱수 반환 (x/y pos 시작)
	auto getMaxSqr = [&](int x, int y) -> int
	{
		// 제곱수 체크
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

		// 등차수열
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
					
					// 중간 확인
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