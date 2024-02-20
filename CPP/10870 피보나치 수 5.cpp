// https://www.acmicpc.net/problem/10870

#include <iostream>
using namespace std;

struct p10870
{
	long long p[21];

	long long getPibo(int i)
	{
		if (i == 0) return 0;
		if (i == 1) return 1;
		if (p[i] != 0) return p[i];
		return p[i] = getPibo(i - 1) + getPibo(i - 2);
	}

	int main()
	{
		int n;
		cin >> n;
		cout << getPibo(n);
	}
};