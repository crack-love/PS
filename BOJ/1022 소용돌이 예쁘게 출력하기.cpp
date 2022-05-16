// https://www.acmicpc.net/problem/1022

#include <iostream>
#include <cmath>
using namespace std;

int p1022()
{
	// r1~r2, c1~c2 범위 스파이럴만 그리기
	// 센터에서 i번째 델타 떨어진 소용돌이로 시작함
	// 
	// 다른 방법: xy위치에 따른 식 정해져 있음, 상하좌우 다른 식)

	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int minDelta = min(r1, c1);
	int maxDelta = max(r2, c2);
	
	int s[5001] = {};
	auto getStartValue = [&](int i, auto& self) -> int
	{
		// si = i번째 소용돌이 시작 값
		// s0 = 1, s1 = 2
		// si = s(i-1) + 8 * (i-1) (when i>=3)

		if (i == 0) 
		{
			return s[i] = 1;
		}
		else if (i == 1)
		{
			return s[i] = 2;
		}
		else if (s[i] != 0)
		{
			return s[i];
		}
		else
		{
			return s[i] = self(i - 1, self) + 8 * (i - 1);
		}
	};

	int maxValue = 1;
	int m[50][5] = {};
	auto set = [&m, r1, r2, c1, c2, &maxValue](int x, int y, int v)
	{
		if (x < r1 || x > r2) return;
		if (y < c1 || y > c2) return;

		m[x - r1][y - c1] = v;
		maxValue = max(maxValue, v);
	};
	set(0, 0, 1);

	// draw spiral border
	auto draw = [&](int i)
	{
		i = abs(i);
		int s = getStartValue(i, getStartValue);
		int x = i - 1;
		int y = i;

		// up
		set(x, y, s);
		for (int j = 0; j < 2 * i - 1; ++j)
		{
			set(--x, y, ++s);
		}

		// left
		for (int j = 0; j < 2 * i; ++j)
		{
			set(x, --y, ++s);
		}
		
		// down 
		for (int j = 0; j < 2 * i; ++j)
		{
			set(++x, y, ++s);
		}
		
		// right
		for (int j = 0; j < 2 * i; ++j)
		{
			set(x, ++y, ++s);
		}
	};

	for (int i = minDelta; i <= maxDelta; ++i) 
	{
		draw(i);
	}

	// print	
	int width = floor(log10(maxValue)) + 1;
	for (int i = 0; i <= r2 - r1; ++i)
	{
		for (int j = 0; j <= c2 - c1; ++j)
		{
			cout.width(width);
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
