// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
#define endl "\n"
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p12852
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		int p[(int)1e6]{};
		queue<int> q;
		q.push(n);
		while (q.size() > 0)
		{
			int x = q.front();
			q.pop();

			if (x <= 1)
			{
				break;
			}

			if (x % 3 == 0 && p[x / 3] == 0)
			{
				p[x / 3] = x;
				q.push(x / 3);
			}
			if (x % 2 == 0 && p[x / 2] == 0)
			{
				p[x / 2] = x;
				q.push(x / 2);
			}
			if (p[x - 1] == 0)
			{
				p[x - 1] = x;
				q.push(x - 1);
			}
		}

		int c = 1;
		vector<int> ans;
		ans.push_back(c);
		while (c != n)
		{
			c = p[c];
			ans.push_back(c);
		}

		cout << ans.size() - 1 << endl;
		for (int i = ans.size() - 1; i >= 0; --i)
		{
			cout << ans[i] << " ";
		}

		return 0;
	}
};