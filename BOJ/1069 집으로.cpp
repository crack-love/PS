// https://www.acmicpc.net/problem/1069
// gold3

#include <iostream>
#include <cmath>
using namespace std;

int p1069()
{
	// ������ ����

	int x, y, d, t;
	cin >> x >> y >> d >> t;

	double dist = sqrt(x * x + y * y);

	// ������ 0�� �ϴ� ���
	double answer = dist;
	
	// ������ 1���� �ϴ� ��� (0,0�� ���� �� ����)
	double d1 = dist - d;
	answer = min(answer, abs(d1) + t);

	// ������ n�� �ϰ� ���� �Ÿ��� �ɾ� ������ ���
	int div = (int)(dist / d);
	double d2 = dist - d * div;
	answer = min(answer, d2 + t * div);

	// ������ n + 1�� �Ͽ��� (������ ����) ������ ������ ���
	if (div == 0) div = 2;
	else div += 1;
	answer = min(answer, (double)t * div);

	cout.precision(9);
	cout.setf(ios::fixed);
	cout << answer << "\n";
	
	return 0;
}