// https://www.acmicpc.net/problem/15080

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p15080
{
	int main()
	{
		fastio;

		int ss[2] = {};
		for1(i, 2)
		{
			string hstr, mstr, sstr, t;
			cin >> hstr >> t >> mstr >> t >> sstr;
			int h = stoi(hstr);
			int m = stoi(mstr);
			int s = stoi(sstr);
			ss[i] = h * 3600 + m * 60 + s;
		}

		if (ss[0] <= ss[1])
		{
			cout << ss[1] - ss[0];
		}
		else
		{
			cout << (3600 * 24 - ss[0]) + ss[1];
		}

		return 0;
	}
};