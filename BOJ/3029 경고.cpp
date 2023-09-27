// https://www.acmicpc.net/problem/3029

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p3029
{
	int tosec(string hms)
	{
		int h = (hms[0] - '0') * 10 + hms[1] - '0';
		int m = (hms[3] - '0') * 10 + hms[4] - '0';
		int s = (hms[6] - '0') * 10 + hms[7] - '0';
		return s + m * 60 + h * 3600;
	}

	string tohms(int sec)
	{
		int s = sec % 60;
		sec /= 60;
		int m = sec % 60;
		sec /= 60;
		int h = sec;
		return (h >= 10 ? to_string(h) : "0" + to_string(h)) + ":" +
			(m >= 10 ? to_string(m) : "0" + to_string(m)) + ":" +
			(s >= 10 ? to_string(s) : "0" + to_string(s));
	}

	int main()
	{
		fastio;

		string bstr, estr;
		cin >> bstr >> estr;

		int beg = tosec(bstr);
		int end = tosec(estr);
		if (beg == end)
		{
			cout << tohms(24 * 3600);
		}
		else if (beg < end)
		{
			cout << tohms(end - beg);
		}
		else
		{
			cout << tohms(end + 24 * 3600 - beg);
		}

		return 0;
	}
};