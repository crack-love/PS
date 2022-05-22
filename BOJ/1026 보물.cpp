// https://www.acmicpc.net/problem/1026
// silver4
// 2016.2.23

#include <cstdio>
#include <algorithm>
const int MAX = 51;

int p1026()
{
	int a[MAX], b[MAX], n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &b[i]); b[i] *= -1;
	}

	std::sort(a, a + n);
	std::sort(b, b + n);

	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i] * -b[i];

	printf("%d\n", sum);
	return 0;
}