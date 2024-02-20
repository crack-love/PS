// https://www.acmicpc.net/problem/13913

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dd[2][4] = { {0,0,1,-1}, { 1,-1,0,0 } };
using namespace std;

struct p13913
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, k;
		cin >> n >> k;

		queue<pair<int, int>> q;
		const int SIZE = 200'000;
		int d[SIZE]{};
		int p[SIZE]{};
		d[n] = 1;
		p[n] = -1;
		q.push({ n, 1 });

		bool finished = false;
		while (q.size() > 0 && !finished)
		{
			auto [x, c] = q.front();
			q.pop();

			for (int nx : {x * 2, x + 1, x - 1})
			{
				if (nx >= 0 && nx < SIZE && d[nx] == 0)
				{
					d[nx] = c + 1;
					p[nx] = x;
					q.push({ nx, c + 1 });

					if (nx == k)
					{
						finished = true;
						break;
					}
				}
			}
		}

		cout << d[k] - 1 << "\n";

		stack<int> st;
		int c = k;
		while (c != -1)
		{
			st.push(c);
			c = p[c];
		}

		while (st.size() > 0)
		{
			cout << st.top() << " ";
			st.pop();
		}

		return 0;
	}
};