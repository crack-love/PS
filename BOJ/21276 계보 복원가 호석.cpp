// https://www.acmicpc.net/problem/21276

#include <bits/stdc++.h>
#define for1(i,r) for(int i=0;i<r;++i)
#define for2(i,j,r,c) for(int i=0;i<r;++i)for(int j=0;j<c;++j)
#define step(i,j,r,c) if (i < 0 || j < 0 || i >= r || j >= c) continue
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
using namespace std;

struct p21276
{
	// !한명의 시조를 root로 하는!

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);

		int n;
		cin >> n;
		map<string, int> nametoi;
		for1(i, n)
		{
			string s;
			cin >> s;
			nametoi.insert({ s, 0 });
		}

		string itoname[1000];
		auto it = nametoi.begin();
		for1(i, n)
		{
			it->second = i;
			itoname[i] = it->first;
			++it;
		}

		vector<int> next[1001];
		int pcnt[1000]{};
		int m;
		cin >> m;
		for1(i, m)
		{
			string x, y;
			cin >> x >> y;

			int xi = nametoi[x];
			int yi = nametoi[y];
			next[yi].push_back(xi);
			pcnt[xi] += 1;
		}

		set<string> root;
		queue<int> q;
		for1(i, n)
		{
			if (pcnt[i] <= 0)
			{
				q.push(i);
				root.insert(itoname[i]);
			}
		}

		set<string> directChild[1000];
		while (q.size() > 0)
		{
			int x = q.front();
			q.pop();

			for (int nx : next[x])
			{
				pcnt[nx] -= 1;
				if (pcnt[nx] == 0)
				{
					directChild[x].insert(itoname[nx]);
					q.push(nx);
				}
			}
		}

		cout << root.size() << "\n";
		for (const auto& s : root)
		{
			cout << s << " ";
		}
		cout << "\n";

		for1(i, n)
		{
			cout << itoname[i] << " ";
			cout << directChild[i].size() << " ";
			for (const auto& s : directChild[i])
			{
				cout << s << " ";
			}
			cout << "\n";
		}

		return 0;
	}
};