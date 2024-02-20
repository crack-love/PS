// https://www.acmicpc.net/problem/27736

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p27736
{
	int main()
	{
		fastio;

		int n;
		int p = 0, neg = 0, d = 0;
		cin >> n;
		for1(i, n)
		{
			int x;
			cin >> x;
			if (x == 1)
				p += 1;
			else if (x == 0)
				d += 1;
			else if (x == -1)
				neg += 1;
		}

		if (n % 2 == 0 && d >= n / 2)
		{
			cout << "INVALID";
			return 0;
		}
		else if (n % 2 == 1 && d > n / 2)
		{
			cout << "INVALID";
			return 0;
		}

		if (p > neg)
		{
			cout << "APPROVED";
		}
		else
		{
			cout << "REJECTED";
		}

		return 0;
	}
};