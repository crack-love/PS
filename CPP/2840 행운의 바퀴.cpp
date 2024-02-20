// https://www.acmicpc.net/problem/2840

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
typedef int64_t ll;
const int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,1,-1,1,-1 };
using namespace std;

struct p2840
{
	int main()
	{
		fastio;

		int n, k;
		cin >> n >> k;

		int p = 0;
		char a[25]{};
		set<char> visited;
		fill(a, a + n, '?');
		for1(i, k)
		{
			int s;
			char c;
			cin >> s >> c;

			p = p - s;
			p += (-(p / n) + 1) * n;
			p %= n;

			if (a[p] == '?')
			{
				if (visited.find(c) != visited.end())
				{
					cout << "!";
					return 0;
				}

				visited.insert(c);
				a[p] = c;
			}
			else if (a[p] == c)
			{
				continue;
			}
			else
			{
				cout << "!";
				return 0;
			}
		}

		for1(i, n)
		{
			cout << a[p];
			p = (p + 1) % n;
		}

		return 0;
	}
};