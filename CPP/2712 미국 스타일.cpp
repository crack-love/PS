// https://www.acmicpc.net/problem/2712

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p2712
{
	int main()
	{
		fastio;

		map<string, double> toV =
		{
			{"kg", 2.2046}, {"lb", 0.4536},
			{"l", 0.2642}, {"g", 3.7854},
		};
		map<string, string> toU =
		{
			{"kg", "lb"}, {"lb", "kg"},
			{"l", "g"}, {"g", "l"},
		};

		int t;
		cin >> t;
		while (t--)
		{
			double v;
			string u;
			cin >> v >> u;

			double v2 = toV[u] * v;
			string u2 = toU[u];

			cout.precision(4);
			cout.setf(cout.fixed);
			cout << v2 << " " << u2 << "\n";
		}

		return 0;
	}
};