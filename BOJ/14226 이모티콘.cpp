// https://www.acmicpc.net/problem/14226

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
using namespace std;

struct p14226
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int s;
		cin >> s;
		int visited[2001][2001]{};// v,clip
		deque<tuple<int, int, int>> q; // t,v,clip
		q.push_back({ 0,1,0 });

		while (!q.empty())
		{
			auto [t, v, clip] = q.front();
			q.pop_front();

			if (v == s)
			{
				cout << t;
				break;
			}

			// copy
			if (clip != v)
			{
				int& vref = visited[v][v];
				if (vref == 0 || vref > t + 1)
				{
					vref = t + 1;
					q.push_back({ t + 1, v, v });
				}
			}
			// paste
			if (v + clip < 2001)
			{
				int& vref = visited[v + clip][clip];
				if (vref == 0 || vref > t + 1)
				{
					vref = t + 1;
					q.push_back({ t + 1, v + clip, clip });
				}
			}
			// erase
			if (v - 1 >= 2)
			{
				int& vref = visited[v - 1][clip];
				if (vref == 0 || vref > t + 1)
				{
					vref = t + 1;
					q.push_back({ t + 1, v - 1, clip });
				}
			}
		}

		return 0;
	}
};