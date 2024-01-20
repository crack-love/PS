// https://www.acmicpc.net/problem/5648

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p5648
{
	int main()
	{
		fastio;

		int n;
		cin >> n;
		vector<string> s(n, "");
		for1(i, n)
		{
			cin >> s[i];
			reverse(all(s[i]));

			int j = 0;
			for (j; j < s[i].size(); ++j)
			{
				if (s[i][j] != '0')
				{
					break;
				}
			}
			if (j > 0)
				s[i] = s[i].substr(j);
		}

		auto pred = [](const string& x, const string& y)
			{
				if (x.length() != y.length())
					return x.length() < y.length();

				return x < y;
			};

		sort(all(s), pred);

		for1(i, n)
		{
			cout << s[i] << "\n";
		}

		return 0;
	}
};