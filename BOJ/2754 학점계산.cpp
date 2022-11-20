// https://www.acmicpc.net/problem/2754

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p2754
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		unordered_map<string, double> m = {
			{"A+", 4.3}, {"A0", 4.0}, {"A-", 3.7},
			{"B+", 3.3}, {"B0", 3.0}, {"B-", 2.7},
			{"C+", 2.3}, {"C0", 2.0}, {"C-", 1.7},
			{"D+", 1.3}, {"D0", 1.0}, {"D-", 0.7},
			{"F", 0.0},
		};
		string s;
		cin >> s;
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << m[s];
		return 0;
	}
};