// https://www.acmicpc.net/problem/2748

#include <iostream>
using namespace std;

struct p2748
{
	long long pibo[91];

	long long getPibo(int i)
	{
		if (i == 0) return 0;
		if (i == 1) return 1;

		if (pibo[i] != 0) return pibo[i];
		else
		{
			return pibo[i] = getPibo(i - 2) + getPibo(i - 1);
		}
	}

	int main()
	{
		int n;
		cin >> n;
		cout << getPibo(n);
		return 0;
	}
};