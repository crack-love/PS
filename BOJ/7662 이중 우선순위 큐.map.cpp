// https://www.acmicpc.net/problem/7662

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p7662_map
{
	int main_1()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int t;
		cin >> t;
		while (t--)
		{
			priority_queue<int> maxq;
			priority_queue<int, vector<int>, greater<int>> minq;
			unordered_map<int, int> cnt;

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
					cnt[v] += 1;
				}
				else if (o == 'D')
				{
					if (v == -1)
					{
						while (minq.size() > 0 && cnt[minq.top()] <= 0)
						{
							minq.pop();
						}

						if (minq.size() > 0)
						{
							v = minq.top();
							minq.pop();
							cnt[v] -= 1;
						}
					}
					else if (v == 1)
					{
						while (maxq.size() > 0 && cnt[maxq.top()] <= 0)
						{
							maxq.pop();
						}

						if (maxq.size() > 0)
						{
							v = maxq.top();
							maxq.pop();
							cnt[v] -= 1;
						}
					}
				}
			}

			while (minq.size() > 0 && cnt[minq.top()] <= 0)
			{
				minq.pop();
			}
			while (maxq.size() > 0 && cnt[maxq.top()] <= 0)
			{
				maxq.pop();
			}

			if (minq.size() > 0)
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