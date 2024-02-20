// https://www.acmicpc.net/problem/14726

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i<0||j<0||i>=r||j>= c) continue
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p14726
{
	int main()
	{
		fastio;

		int t;
		cin >> t;
		while (t--)
		{
			string str;
			cin >> str;
			int sum = 0;
			for1(i, str.size())
			{
				int v = str[str.size() - 1 - i] - '0';

				if (i % 2 == 1)
				{
					v *= 2;
					if (v >= 10)
					{
						v = v % 10 + v / 10;
					}
				}

				sum += v;
			}

			cout << (sum % 10 == 0 ? "T" : "F") << "\n";
		}

		return 0;
	}
};