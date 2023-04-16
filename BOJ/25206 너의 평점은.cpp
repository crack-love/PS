// https://www.acmicpc.net/problem/25206

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };

using namespace std;

struct p25206
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		map<string, double> m;
		m.insert({ "A+", 4.5 });
		m.insert({ "A0", 4.0 });
		m.insert({ "B+", 3.5 });
		m.insert({ "B0", 3.0 });
		m.insert({ "C+", 2.5 });
		m.insert({ "C0", 2.0 });
		m.insert({ "D+", 1.5 });
		m.insert({ "D0", 1.0 });
		m.insert({ "F", 0.0 });

		int vsum = 0;
		double ssum = 0;
		for1(i, 20)
		{
			string name;
			double value;
			string score;
			cin >> name >> value >> score;

			if (score == "P")
			{
				continue;
			}
			else
			{
				vsum += value;
				ssum += value * m[score];
			}
		}

		cout << ssum / vsum;

		return 0;
	}
};