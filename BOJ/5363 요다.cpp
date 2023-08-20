// https://www.acmicpc.net/problem/5363

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p5363
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		string l;
		getline(cin, l);
		int n = stoi(l);
		for1(i, n)
		{
			getline(cin, l);

			int p0 = l.find(' ');
			int p1 = l.find(' ', p0 + 1);

			cout << l.substr(p1 + 1) << ' ';
			cout << l.substr(0, p1 + 1) << "\n";
		}

		return 0;
	}
};