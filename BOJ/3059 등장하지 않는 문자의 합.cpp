// https://www.acmicpc.net/problem/3059

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p3059
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			string s;
			cin >> s;
			bool a[26]{};
			for1(i, s.size())
			{
				a[s[i] - 'A'] = true;
			}

			int sum = 0;
			for1(i, 26)
			{
				sum += !a[i] ? 'A' + i : 0;
			}

			cout << sum << endl;
		}

		return 0;
	}
};