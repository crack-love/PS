// https://www.acmicpc.net/problem/1408

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p1408
{
	int toSec(const string& a)
	{
		int cs = 0;
		cs += (a[0] - '0') * 10 + a[1] - '0';
		cs *= 60;
		cs += (a[3] - '0') * 10 + a[4] - '0';
		cs *= 60;
		cs += (a[6] - '0') * 10 + a[7] - '0';
		return cs;
	}

	void fromSec(int s, string& a)
	{
		a[7] = s % 60 % 10 + '0';
		a[6] = s % 60 / 10 + '0';
		s /= 60;
		a[4] = s % 60 % 10 + '0';
		a[3] = s % 60 / 10 + '0';
		s /= 60;
		a[1] = s % 60 % 10 + '0';
		a[0] = s % 60 / 10 + '0';
		s /= 60;
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		// beg < curr
		// ans = 24 - (curr - beg)
		// beg > curr
		// ans = beg - curr

		string c, b;
		cin >> c >> b;
		int cSec = toSec(c);
		int bSec = toSec(b);

		int ans;
		if (bSec > cSec)
		{
			ans = bSec - cSec;
		}
		else if (bSec < cSec)
		{
			ans = 60 * 60 * 24 - (cSec - bSec);
		}

		fromSec(ans, c);
		cout << c;

		return 0;
	}
};