// https://www.acmicpc.net/problem/17299

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p17299
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int a[(int)1e6]{};
		int c[(int)1e6 + 1]{};
		for1(i, n)
		{
			cin >> a[i];
			c[a[i]] += 1;
		}

		int ans[(int)1e6]{};
		stack<int> s;

		for (int i = n - 1; i >= 0; --i)
		{
			while (true)
			{
				if (s.empty())
				{
					ans[i] = -1;
					break;
				}
				else if (c[a[i]] >= c[s.top()])
				{
					s.pop();
				}
				else if (c[a[i]] < c[s.top()])
				{
					ans[i] = s.top();
					break;
				}
			}

			s.push(a[i]);
		}

		for1(i, n)
		{
			cout << ans[i] << " ";
		}

		return 0;
	}
};