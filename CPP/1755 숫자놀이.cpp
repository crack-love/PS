// https://www.acmicpc.net/problem/1755

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p1755
{
	int main()
	{
		fastio;

		int n, m;
		cin >> m >> n;
		map<string, int> s;
		const string is[] = { "zero", "one", "two", "three",
		"four", "five",	"six", "seven", "eight", "nine" };
		for (int i = m; i <= n; ++i)
		{
			if (i < 10)
			{
				s.insert({ is[i], i });
			}
			else
			{
				s.insert({ is[i / 10] + " " + is[i % 10], i });
			}
		}

		int cnt = 0;
		for (auto it : s)
		{
			cout << it.second << " ";
			if (++cnt % 10 == 0)
				cout << "\n";
		}

		return 0;
	}
};