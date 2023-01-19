// https://www.acmicpc.net/problem/7662

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p7662
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			priority_queue<int> maxq;
			priority_queue<int> maxqErase;
			priority_queue<int, vector<int>, greater<int>> minq;
			priority_queue<int, vector<int>, greater<int>> minqErase;

			int k;
			cin >> k;
			while (k--)
			{
				char o;
				int v;
				cin >> o >> v;
				if (o == 'I')
				{
					maxq.push(v);
					minq.push(v);
				}
				else if (o == 'D')
				{
					if (v == -1)
					{
						while (minqErase.size() > 0 && minqErase.top() == minq.top())
						{
							minq.pop();
							minqErase.pop();
						}
						if (minq.size() > 0)
						{
							v = minq.top();
							minq.pop();
							maxqErase.push(v);
						}
					}
					else if (v == 1)
					{
						while (maxqErase.size() > 0 && maxqErase.top() == maxq.top())
						{
							maxq.pop();
							maxqErase.pop();
						}
						if (maxq.size() > 0)
						{
							v = maxq.top();
							maxq.pop();
							minqErase.push(v);
						}
					}
				}
			}

			while (minqErase.size() > 0 && minq.top() == minqErase.top())
			{
				minqErase.pop();
				minq.pop();
			}
			while (maxqErase.size() > 0 && maxq.top() == maxqErase.top())
			{
				maxqErase.pop();
				maxq.pop();
			}

			if (maxq.size() > 0)
			{
				cout << maxq.top() << " " << minq.top() << "\n";
			}
			else
			{
				cout << "EMPTY\n";
			}
		}

		return 0;
	}
};