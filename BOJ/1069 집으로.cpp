// https://www.acmicpc.net/problem/1069
// gold3

#include <iostream>
#include <cmath>
using namespace std;

int p1069()
{
	// 기하학 문제

	int x, y, d, t;
	cin >> x >> y >> d >> t;

	double dist = sqrt(x * x + y * y);

	// 점프를 0번 하는 경우
	double answer = dist;
	
	// 점프를 1번만 하는 경우 (0,0을 넘을 수 있음)
	double d1 = dist - d;
	answer = min(answer, abs(d1) + t);

	// 점프를 n번 하고 남은 거리는 걸어 들어오는 경우
	int div = (int)(dist / d);
	double d2 = dist - d * div;
	answer = min(answer, d2 + t * div);

	// 점프를 n + 1번 하여서 (각도를 맞춰) 완전히 들어오는 경우
	if (div == 0) div = 2;
	else div += 1;
	answer = min(answer, (double)t * div);

	cout.precision(9);
	cout.setf(ios::fixed);
	cout << answer << "\n";
	
	return 0;
}