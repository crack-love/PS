// https://www.acmicpc.net/problem/14907

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p14097
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int dur[26]{};
		vector<int> prev[26]{};
		vector<int> next[26];
		int pcnt[26]{};

		queue<int> q;
		while (true)
		{
			if (cin.get() == EOF)
			{
				break;
			}
			cin.unget();

			string line;
			getline(cin, line);

			char w = line[0];
			int i = w - 'A';
			if (isalpha(line[line.size() - 1]))
			{
				dur[i] = stoi(line.substr(2, line.find(' ', 2) - 2));
				string prevStr = line.substr(line.find_last_of(' ', line.size()) + 1);
				for (char c : prevStr)
				{
					prev[i].push_back(c - 'A');
				}
			}
			else
			{
				dur[i] = stoi(line.substr(2));
			}

			for (int p : prev[i])
			{
				next[p].push_back(i);
			}

			pcnt[i] = prev[i].size();
			if (pcnt[i] == 0)
			{
				q.push(i);
			}
		}

		int minTime[26]{};
		while (q.size() > 0)
		{
			int x = q.front();
			q.pop();

			for (int px : prev[x])
			{
				minTime[x] = max(minTime[px], minTime[x]);
			}
			minTime[x] += dur[x];

			for (int nx : next[x])
			{
				pcnt[nx] -= 1;
				if (pcnt[nx] == 0)
				{
					q.push(nx);
				}
			}
		}

		int ans = 0;
		for1(i, 26)
		{
			ans = max(ans, minTime[i]);
		}

		cout << ans;
		return 0;
	}
};