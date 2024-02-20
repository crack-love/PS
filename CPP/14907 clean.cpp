// https://www.acmicpc.net/problem/14907

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p14907
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int dur[26]{};
		vector<int> next[26];
		int pcnt[26]{};

		queue<int> q;
		string line;
		while (getline(cin, line))
		{
			stringstream ss(line);
			char w;
			ss >> w;
			int i = w - 'A';
			ss >> dur[i];
			string pstr;
			ss >> pstr;
			for (char p : pstr)
			{
				int pi = p - 'A';
				next[pi].push_back(i);
			}
			pcnt[i] = pstr.size();
			if (pcnt[i] == 0)
				q.push(i);
		}

		int minTime[26]{};
		while (q.size() > 0)
		{
			int x = q.front();
			q.pop();
			minTime[x] += dur[x];

			for (int nx : next[x])
			{
				minTime[nx] = max(minTime[x], minTime[nx]);

				pcnt[nx] -= 1;
				if (pcnt[nx] == 0)
				{
					q.push(nx);
				}
			}
		}

		cout << *max_element(minTime, minTime + 26);
		return 0;
	}
};