// https://www.acmicpc.net/problem/11286

#include <bits/stdc++.h>
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p11286
{
	class pr
	{
	public:
		bool operator() (int x, int y)
		{
			int ax = abs(x), ay = abs(y);
			if (ax == ay)
			{
				return x > y;
			}
			else
			{
				return ax > ay;
			}
		}
	};

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		priority_queue<int, vector<int>, pr> q;
		int n;
		cin >> n;
		while (n--)
		{
			int x;
			cin >> x;
			if (x != 0)
			{
				q.push(x);
			}
			else
			{
				if (q.empty())
				{
					cout << 0 << "\n";
				}
				else
				{
					cout << q.top() << "\n";
					q.pop();
				}
			}
		}

		return 0;
	}
};