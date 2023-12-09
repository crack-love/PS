// https://www.acmicpc.net/problem/20546

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p20546
{
	int main()
	{
		fastio;
		int v0;
		cin >> v0;
		int v1 = v0;
		int a[14];
		for1(i, 14)
		{
			cin >> a[i];
		}

		int c0 = 0;
		for1(i, 14)
		{
			if (v0 >= a[i])
			{
				c0 += v0 / a[i];
				v0 -= (v0 / a[i]) * a[i];
			}
		}

		int c1 = 0;
		int cons = 0;
		for (int i = 1; i < 14; ++i)
		{
			if (a[i] > a[i - 1])
			{
				cons = cons >= 0 ? cons + 1 : 1;
			}
			else if (a[i] < a[i - 1])
			{
				cons = cons <= 0 ? cons - 1 : -1;
			}
			else
			{
				cons = 0;
			}

			if (cons >= 3)
			{
				v1 += c1 * a[i];
				c1 = 0;
			}
			else if (cons <= -3)
			{
				c1 += v1 / a[i];
				v1 -= (v1 / a[i]) * a[i];
			}
		}

		int p0 = c0 * a[13] + v0;
		int p1 = c1 * a[13] + v1;
		cout << (p0 > p1 ? "BNP" : (p0 < p1 ? "TIMING" : "SAMESAME"));
		return 0;
	}
};