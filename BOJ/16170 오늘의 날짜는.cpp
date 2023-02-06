// https://www.acmicpc.net/problem/16170

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p16170
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		time_t now = time(0);
		tm* gmtm = gmtime(&now);
		cout << gmtm->tm_year + 1900 << "\n";
		cout << gmtm->tm_mon + 1 << "\n";
		cout << gmtm->tm_mday << "\n";

		return 0;
	}
};