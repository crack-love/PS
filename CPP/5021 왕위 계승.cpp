// https://www.acmicpc.net/problem/5021

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p5021
{
	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n, m;
		string root;
		cin >> n >> m >> root;

		map<string, vector<string>> par;
		map<string, vector<string>> child;
		for1(i, n)
		{
			string a, x, y;
			cin >> a >> x >> y;
			par[a].push_back(x);
			par[a].push_back(y);
			child[x].push_back(a);
			child[y].push_back(a);
		}

		queue<string> q;
		map<string, int> pcnt;
		for (auto& pair : par)
		{
			pcnt[pair.first] = pair.second.size();
		}
		for (auto& pair : child)
		{
			if (par.find(pair.first) == par.end())
				q.push(pair.first);
		}

		map<string, double> pure;
		pure[root] = 1;
		while (q.size() > 0)
		{
			string x = q.front();
			q.pop();

			for (string& c : child[x])
			{
				pcnt[c] -= 1;
				if (pcnt[c] == 0)
				{
					double cpure = 0;
					if (par[c].size() > 0)
					{
						for (string& p : par[c])
						{
							cpure += pure[p];
						}
						cpure /= par[c].size();
					}

					pure[c] = cpure;
					q.push(c);
				}
			}
		}

		string ans;
		double ansPure = 0;
		for1(i, m)
		{
			string x;
			cin >> x;
			double xp = pure[x];
			if (xp > ansPure)
			{
				ansPure = xp;
				ans = x;
			}
		}

		cout << ans;
		return 0;
	}
};